#!/usr/bin/env python
import threading
from multiprocessing import Process, Value, Array

shared_balance = Value('i', 0)

class Deposit(threading.Thread):
    def run(self):
        for _ in xrange(1000000):
            global shared_balance
            balance = shared_balance.value
            balance += 100
            shared_balance.value = balance

class Withdraw(threading.Thread):
    def run(self):
        for _ in xrange(1000000):
            global shared_balance
            balance = shared_balance.value
            balance -= 100
            shared_balance.value = balance

threads = [Deposit(), Withdraw()]

for thread in threads:
    thread.start()

for thread in threads:
    thread.join()

print shared_balance.value
