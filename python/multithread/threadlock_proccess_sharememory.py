#!/usr/bin/env python
import threading
from multiprocessing import Process, Value, Array
from multiprocessing import Process, Lock

shared_balance = Value('i', 0)
lock = Lock()

class Deposit(threading.Thread):
    def run(self):
        for _ in xrange(1000000):
            lock.acquire()
            global shared_balance
            balance = shared_balance.value
            balance += 100
            shared_balance.value = balance
            lock.release()

class Withdraw(threading.Thread):
    def run(self):
        for _ in xrange(1000000):
            lock.acquire()
            global shared_balance
            balance = shared_balance.value
            balance -= 100
            shared_balance.value = balance
            lock.release()

threads = [Deposit(), Withdraw()]



def deposit_func(shared_balance):
    for _ in xrange(100):
        lock.acquire()
        balance = shared_balance.value
        balance += 100
        shared_balance.value = balance
        lock.release()

def withdraw_func(shared_balance):
    for _ in xrange(100):
        lock.acquire()
        balance = shared_balance.value
        balance -= 100
        shared_balance.value = balance
        lock.release()


p_deposit = Process(target=deposit_func, args=(shared_balance,))

p_withdraw = Process(target=withdraw_func, args=(shared_balance,))


for thread in threads:
    thread.start()

for thread in threads:
    thread.join()


p_deposit.start()
p_withdraw.start()

p_deposit.join()
p_withdraw.join()


print shared_balance.value



