import numpy as np
from sklearn.datasets import load_digits
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt

digits = load_digits()

digits_df = digits.images.reshape((len(digits.target), -1))
digits_tf = digits.target

X_train_org, X_test_org, y_train_num, y_test = train_test_split(digits_df, digits_tf, test_size= 0.20, random_state= 101)

sc = StandardScaler()
X_train = sc.fit_transform(X_train_org)
X_test = sc.transform(X_test_org)

n_classes = 10

y_train = np.zeros((y_train_num.shape[0],10))
for i in range(n_classes):
    y_train[:,i] = (y_train_num == i)
    
def sigmoid(x):
    x = np.where(x < 0, np.exp(x)/(1 + np.exp(x)), 1/(1 + np.exp(-x)))
    return x

def softmax(x):
    x = x - np.max(x, axis=-1, keepdims=True)
    x = np.exp(x)
    xs = np.sum(x, axis=-1, keepdims=True)
    return x / xs

class myDenseLayer:
    def __init__(self, n_out, n_in):
        self.wegt = np.zeros((n_out, n_in))
        self.bias = np.zeros((n_out))

    def forward(self, x):
        x_lin = np.transpose((np.dot(self.wegt, x) + self.bias), (1, 0, 2))
        return x_lin

    def backward(self, x, x_in):
        dw = np.dot(x.T, x_in)
        db = np.sum(x, axis=0)
        wdJdz = np.dot(x, self.wegt)
        return dw, db, wdJdz
    
def dJdz_sigmoid(wdJdz_upper, az):
    dJdz = wdJdz_upper * az * (1-az)
    return dJdz

def dJdz_softmax(y_hat, y):
    y_hat = y_hat.reshape(y.shape)
    dJdz = y_hat - y
    return dJdz

def my_forward(l, X_in):
    a_1 = sigmoid(np.dot(X_in, np.transpose(l[0].wegt)) + l[0].bias) # first stage forward
    a_2 = sigmoid(np.dot(a_1, np.transpose(l[1].wegt)) + l[1].bias) # second stage forward
    a_3 = sigmoid(np.dot(a_2, np.transpose(l[2].wegt)) + l[2].bias) # third stage forward
    return a_1, a_2, a_3

def my_backward(l, a_1, a_2, a_3, X_in, y_true):
    dw_3, db_3, wdJdz_3 = l[2].backward(dJdz_softmax(a_3, y_true), a_2)    # go through 3rd stage backward
    dw_2, db_2, wdJdz_2 = l[1].backward(dJdz_sigmoid(wdJdz_3, a_2), a_1)    # go through 2nd stage backward
    dw_1, db_1, _       = l[0].backward(dJdz_sigmoid(wdJdz_2, a_1), X_in.T)    # go through 1st stage backward

    d_1 = [dw_1, db_1]
    d_2 = [dw_2, db_2]
    d_3 = [dw_3, db_3]
    
    return d_1, d_2, d_3

def my_loss(l, X_in, y_true):
    _, _, a_3 = my_forward(l[0], l[1], l[2], X_in)
    loss = np.mean((a_3 - y_true))
    return loss

def my_predict(l, X_in):
    _, _, a_3 = my_forward(l[0], l[1], l[2], X_in)
    pred = np.argmax(a_3, axis=1)
    return pred

n_inputs  = 64
n_hidden1 = 80
n_hidden2 = 70
n_classes = 10

l1 = myDenseLayer(n_hidden1, n_inputs)
l2 = myDenseLayer(n_hidden2, n_hidden1)
l3 = myDenseLayer(n_classes, n_hidden2)

layers = [l1, l2, l3]

l1.wegt = np.random.randn(n_hidden1, n_inputs)
l2.wegt = np.random.randn(n_hidden2, n_hidden1)
l3.wegt = np.random.randn(n_classes, n_hidden2)

def create_mini_batches(X, y, batch_size=64):
    mini_batches = []
    n_minibatches = (X.shape[0] // batch_size)
    n_variables = X.shape[1]
    
    data = np.hstack((X, y))
    np.random.shuffle(data)
    
    for i in range(n_minibatches):
        mini_batch = data[i * batch_size: (i + 1) * batch_size, :]
        X_mini, y_mini = mini_batch[:, :-1], mini_batch[:, -1].reshape((-1, 1))
        mini_batches.append((X_mini, y_mini))

    if data.shape[0] % batch_size != 0:
        mini_batch = data[n_minibatches * batch_size:, :]
        X_mini, y_mini = mini_batch[:, :-1], mini_batch[:, -1].reshape((-1, 1))
        mini_batches.append((X_mini, y_mini))

    return mini_batches

class myOptParam:
    def __init__(self, n_out, n_in):
        # Previoud delta values for momentum optimizer
        self.W_dt = np.zeros((n_out, n_in))
        self.B_dt = np.zeros(n_out)
        # Variables for other optimizers
        self.W_mt = np.zeros((n_out, n_in))
        self.B_mt = np.zeros(n_out)
        self.W_vt = np.zeros((n_out, n_in))
        self.B_vt = np.zeros(n_out)

def my_optimizer(lyr, opt, W_grad, B_grad, solver='sgd', learning_rate=0.01, iter=1):
    epsilon = 1e-8
    alpha = eta = learning_rate

    if iter==0:
        print('iteration should start from 1.')

    # optimizer routines
    if  solver=='sgd':
        W_dlt = alpha * W_grad
        B_dlt = alpha * B_grad
    else:  
        print('optimizer error')

    lyr.wegt = lyr.wegt - W_dlt
    lyr.bias = lyr.bias - B_dlt
    return

np.random.seed(1)

lyr = myDenseLayer(2,3)
opt = myOptParam(2,3)

lyr.wegt = np.random.randn(2,3)
lyr.bias = np.random.randn(2)
opt.W_dt = np.random.randn(2,3)
opt.B_dt = np.random.randn(2)
opt.W_mt = np.random.randn(2,3)
opt.B_mt = np.random.randn(2)
opt.W_vt = np.abs(np.random.randn(2,3))
opt.B_vt = np.abs(np.random.randn(2))

W_grad = np.random.randn(2,3)
B_grad = np.random.randn(2)

o1 = myOptParam(n_hidden1, n_inputs)
o2 = myOptParam(n_hidden2, n_hidden1)
o3 = myOptParam(n_classes, n_hidden2)

optimizer ='sgd'
alpha = 0.01
n_epochs = 1000

for epoch in range(n_epochs):

    batches = create_mini_batches(X_train, y_train, batch_size=64)
    for one_batch in batches:
        X_mini, y_mini = one_batch
        batch_len = X_mini.shape[0]
        
        a_1, a_2, a_3 = my_forward(layers, X_mini)
        
        d_1, d_2, d_3 = my_backward(layers, a_1, a_2, a_3, X_mini, y_mini)

        dw_1, db_1 = d_1
        dw_2, db_2 = d_2
        dw_3, db_3 = d_3
        
        my_optimizer(l1, o1, dw_1, db_1, solver=optimizer, learning_rate=alpha, iter=epoch+1)
        my_optimizer(l2, o2, dw_2, db_2, solver=optimizer, learning_rate=alpha, iter=epoch+1)
        my_optimizer(l3, o3, dw_3, db_3, solver=optimizer, learning_rate=alpha, iter=epoch+1)

    if ((epoch+1)%100==0):
        loss_J = my_loss(layers, X_train, y_train)
        print('Epoch: %4d,  loss: %10.8f' % (epoch+1, loss_J))
