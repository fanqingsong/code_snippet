#!/usr/bin/env python
import threading

shared_balance = 0

class Deposit(threading.Thread):
    def run(self):
        for _ in xrange(1000000):
            global shared_balance
            balance = shared_balance
            balance += 100
            shared_balance = balance

class Withdraw(threading.Thread):
    def run(self):
        for _ in xrange(1000000):
            global shared_balance
            balance = shared_balance
            balance -= 100
            shared_balance = balance

threads = [Deposit(), Withdraw()]

for thread in threads:
    thread.start()

for thread in threads:
    thread.join()

print shared_balance
