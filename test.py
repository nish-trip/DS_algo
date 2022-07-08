
'''class Employee():
    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        self.pay = pay
        self.email = last+first+"@gmail.com"

    def fullname(self):
        #print(f"{self.first}{self.last}")
        return "{} {}".format(self.first, self.last)

    @classmethod
    def from_string(cls, emp_str):
        first,last,pay = emp_str.split('-')
        return cls(first,last,pay)

class Developer(Employee):
    pass


e1 = Employee("nishant", "tripathy", 30000)
dev1 = Developer("temp","name",0)

l1 = [[letter,num] for letter in "abcd" for num in range(4)]
print(l1)'''

import concurrent.futures

import time

start = time.perf_counter()


def do_something(seconds):
    print(f'Sleeping {seconds} second(s)...')
    time.sleep(seconds)
    return f'Done Sleeping...{seconds}'

with concurrent.futures.ThreadPoolExecutor as executor:
    results = [executor.submit(do_something, 1) for _ in range(10)]
    


finish = time.perf_counter()