#!/usr/bin/env python
import threading

shared_balance = 0

lock = threading.Lock()

class Deposit(threading.Thread):
    def run(self):
        for _ in xrange(1000000):
            lock.acquire()
            global shared_balance
            balance = shared_balance
            balance += 100
            shared_balance = balance
            lock.release()

class Withdraw(threading.Thread):
    def run(self):
        for _ in xrange(1000000):
            lock.acquire()
            global shared_balance
            balance = shared_balance
            balance -= 100
            shared_balance = balance
            lock.release()

threads = [Deposit(), Withdraw()]

for thread in threads:
    thread.start()

for thread in threads:
    thread.join()

print shared_balance
