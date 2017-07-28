# finalproject
CIS22C Team Project

This was the course-long team project for CIS 22C - Data Structures at De Anza College for Spring 2017.

Our task was to create a simulated online marketplace where users can purchase items of a specific type (ours was robots), or act as employees and ship orders.

The specifications include:
- Read each item from an input file into two binary search trees - one sorted by primary key (name), another by secondary key (ASIN).
- Allow users to search the trees for items, and create orders. Orders are stored in a max heap (priority queue). The heap is organized by order time and shipping speed.
- After an order is created, the user enters customer data. Customers are stored in a hash table.
- The user interface has two main options - employee or customer controls. 
- Customers can search for items and create orders.
- Employees can list orders, ship them, add new robots, or delete robots.
