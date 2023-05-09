class Customer:
    def __init__(self, priority, name):
        self.priority = priority
        self.name = name

    def __repr__(self):
        return f'Customer({self.priority}, {self.name})'


class PriorityQueue:
    def __init__(self):
        self.queue = []

    def push_back(self, customer):
        if not self.queue:
            self.queue.append(customer)
        else:
            for i, c in enumerate(self.queue):
                if customer.priority < c.priority:
                    self.queue.insert(i, customer)
                    break
            else:
                self.queue.append(customer)

    def pop_front(self):
        if not self.queue:
            return None
        return self.queue.pop(0)

    def __repr__(self):
        return f'PriorityQueue({self.queue})'


# Example usage
pq = PriorityQueue()
pq.push_back(Customer(3, 'Alice'))
pq.push_back(Customer(1, 'Bob'))
pq.push_back(Customer(2, 'Cesar'))

print(pq.pop_front())  # Customer(1, Bob)
print(pq.pop_front())  # Customer(2, Cesar)
print(pq.pop_front())  # Customer(3, Alice)
print(pq.pop_front())  # None
