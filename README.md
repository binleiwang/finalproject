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

UML:

![UML Image](https://raw.githubusercontent.com/binleiwang/finalproject/master/umlsample.png)

Sample Run:

```
Welcome to Robot Land!
This program simulates a marketplace where you can buy and sell robots.
It utilizes several data structures, such as a heap, hash table, binary search trees, and linked lists.
You may interact with the item database as either a customer (to search and order Robots),
or an employee (to ship/view orders and add/delete Robots from the store.

========================= Main Menu ==========================
Please type C for customer, E for employee, or type Q to quit.
c
Welcome to our robot store!  

1 - Search for a product
    - Find and display one record using the primary key (name)
    - Find and display one record using the secondary key (ASIN - Amazon ID Number)
2 - List Full Product Details
    - List data sorted by primary key
    - List data sorted by secondary key
3 - List Mini Product Menu
Q - Quit

Please choose option 1, 2, 3 or Q to quit: 1
_______________________Shortlist of Robots_______________________
_________Name______________________________________ASIN__________
             4M Doodling Robot || B002EWWW9O
                4M Smart Robot || B001XQ1N2E
              4M Tin Can Robot || B0014WO96Y
Autel Robotics X-Star Premium Drone || B01B1H8322
Cheerwing Syma X5SW-V3 FPV Explorers2 2.4Ghz 4CH 6-Axis Gyro RC Headless Quadcopter Drone || B011JV9HA2
                         Cozmo || B01GA1298S 
DJI Phantom P3-STANDARD Quadcopter Drone with 2.7K HD Video Camera || B013U0F6EQ
H456 Abb Industrial Robot Mechanical Arm || B01M9DQUAS
Kohstar S520 4th generation robot lawn mower || B06WD7MT8W
LEGO 31313 Mindstorms Programmable EV3 Customizable Robot with Sensors || B00BMKLVJ6
LEGO Creator Robo Explorer 31062 Building Kit || B01KJEO7TQ
                      Miposaur || B00VFZDOC0
          OWI Robotic Arm Edge || B0017OFRCY
OWI Salt Water Fuel Cell Giant Arachnoid Kit || B007V5YYWM
Snov Surveillance Moving Robot || B01G7CEBDG
Sphero Ollie Darkside App-Controlled Robot || B00W4Z8DRQ
Sphero SPRK+ STEAM Educational Robot || B01GZ1S7OS
   Sphero Star Wars BB-8 Droid || B0107H5FJ6
Telebrands,Robo Stir Automatic Pot Stirer, As Seen On Tv Clamshell || B004PZ7FPY
       Traxxas Aton Quadcopter || B019OQEIPI
    WowWee - MiP the Toy Robot || B00KMSOIGM
Yipa 3D Flip Mini RC Drone with LED Flash Light 29mm 2.4G 4CH 6 Axis Gyro CX-10 UFO Quadcopter || B01NARDYUQ
Zodiac MX6 Automatic In Ground Pool Cleaner || B00IG9LZ4C
        eDrawBot Drawing Robot || B06XC7G3JL
iRobot Roomba 650 Robotic Vacuum Cleaner || B008LX6OC6
_________________________________________________________________
Do you want to search for the product by name or ASIN (ID#)? name
Please enter a name to search for: 4M Smart Robot
Information of robot 4M Smart Robot
- ASIN: B001XQ1N2E
- Price: 10.89
- Manufacture: 4M
- Purpose: Moving robot toy
- User: everyone
- Weight: 0.6
- Rating: 2.0
- Quantity: 25

Do you want to purchase this product? yes
Adding 4M Smart Robot to your order.
Do you want to search for another product? no
The product is your added to your order list.

Chose your shipping method:
    O - Over night ($10.99)
    R - Rush ($6.99)
    S - Standard ($3.99)
o


Please enter your purchase information: 
First name: Testy
Last name: Tester
Street address: 123 Test St.
City: Testopia
State: TE
Zip: 12345
Viewing Purchase:
---------------------------------------------------
Order number: 1001
Item 1: 4M Smart Robot
Price: $10.9
Order time: Thu Jul 27 23:11:22 2017
Shipping option: Overnight shipping  Shipped yet: No
Price before tax and handling: $10.89
Tax: $0.98
Shipping fee: $10.99
Total price: $23.85
---------------------------------------------------

Inserting Order #1001. Heap size: 1
Returning to Main Menu.

========================= Main Menu ==========================
Please type C for customer, E for employee, or type Q to quit.
c
Welcome to our robot store!  

1 - Search for a product
    - Find and display one record using the primary key (name)
    - Find and display one record using the secondary key (ASIN - Amazon ID Number)
2 - List Full Product Details
    - List data sorted by primary key
    - List data sorted by secondary key
3 - List Mini Product Menu
Q - Quit

Please choose option 1, 2, 3 or Q to quit: 1
_______________________Shortlist of Robots_______________________
_________Name______________________________________ASIN__________
             4M Doodling Robot || B002EWWW9O
                4M Smart Robot || B001XQ1N2E
              4M Tin Can Robot || B0014WO96Y
Autel Robotics X-Star Premium Drone || B01B1H8322
Cheerwing Syma X5SW-V3 FPV Explorers2 2.4Ghz 4CH 6-Axis Gyro RC Headless Quadcopter Drone || B011JV9HA2
                         Cozmo || B01GA1298S 
DJI Phantom P3-STANDARD Quadcopter Drone with 2.7K HD Video Camera || B013U0F6EQ
H456 Abb Industrial Robot Mechanical Arm || B01M9DQUAS
Kohstar S520 4th generation robot lawn mower || B06WD7MT8W
LEGO 31313 Mindstorms Programmable EV3 Customizable Robot with Sensors || B00BMKLVJ6
LEGO Creator Robo Explorer 31062 Building Kit || B01KJEO7TQ
                      Miposaur || B00VFZDOC0
          OWI Robotic Arm Edge || B0017OFRCY
OWI Salt Water Fuel Cell Giant Arachnoid Kit || B007V5YYWM
Snov Surveillance Moving Robot || B01G7CEBDG
Sphero Ollie Darkside App-Controlled Robot || B00W4Z8DRQ
Sphero SPRK+ STEAM Educational Robot || B01GZ1S7OS
   Sphero Star Wars BB-8 Droid || B0107H5FJ6
Telebrands,Robo Stir Automatic Pot Stirer, As Seen On Tv Clamshell || B004PZ7FPY
       Traxxas Aton Quadcopter || B019OQEIPI
    WowWee - MiP the Toy Robot || B00KMSOIGM
Yipa 3D Flip Mini RC Drone with LED Flash Light 29mm 2.4G 4CH 6 Axis Gyro CX-10 UFO Quadcopter || B01NARDYUQ
Zodiac MX6 Automatic In Ground Pool Cleaner || B00IG9LZ4C
        eDrawBot Drawing Robot || B06XC7G3JL
iRobot Roomba 650 Robotic Vacuum Cleaner || B008LX6OC6
_________________________________________________________________
Do you want to search for the product by name or ASIN (ID#)? name
Please enter a name to search for: iRobot Roomba 650 Robotic Vacuum Cleaner
Information of robot iRobot Roomba 650 Robotic Vacuum Cleaner
- ASIN: B008LX6OC6
- Price: 299.99
- Manufacture: iRobot
- Purpose: Vacuum cleaner
- User: adult
- Weight: 11.1
- Rating: 4.0
- Quantity: 25

Do you want to purchase this product? yes
Adding iRobot Roomba 650 Robotic Vacuum Cleaner to your order.
Do you want to search for another product? no
The product is your added to your order list.

Chose your shipping method:
    O - Over night ($10.99)
    R - Rush ($6.99)
    S - Standard ($3.99)
r


Please enter your purchase information: 
First name: Other
Last name: Tester
Street address: 999 Testing Lane
City: Testerton
State: TA
Zip: 98765
Viewing Purchase:
---------------------------------------------------
Order number: 1002
Item 1: iRobot Roomba 650 Robotic Vacuum Cleaner
Price: $300.0
Order time: Thu Jul 27 23:12:43 2017
Shipping option: Rush shipping  Shipped yet: No
Price before tax and handling: $299.99
Tax: $27.00
Shipping fee: $6.99
Total price: $334.61
---------------------------------------------------

Inserting Order #1002. Heap size: 2
Returning to Main Menu.

========================= Main Menu ==========================
Please type C for customer, E for employee, or type Q to quit.
c
Welcome to our robot store!  

1 - Search for a product
    - Find and display one record using the primary key (name)
    - Find and display one record using the secondary key (ASIN - Amazon ID Number)
2 - List Full Product Details
    - List data sorted by primary key
    - List data sorted by secondary key
3 - List Mini Product Menu
Q - Quit

Please choose option 1, 2, 3 or Q to quit: 1
_______________________Shortlist of Robots_______________________
_________Name______________________________________ASIN__________
             4M Doodling Robot || B002EWWW9O
                4M Smart Robot || B001XQ1N2E
              4M Tin Can Robot || B0014WO96Y
Autel Robotics X-Star Premium Drone || B01B1H8322
Cheerwing Syma X5SW-V3 FPV Explorers2 2.4Ghz 4CH 6-Axis Gyro RC Headless Quadcopter Drone || B011JV9HA2
                         Cozmo || B01GA1298S 
DJI Phantom P3-STANDARD Quadcopter Drone with 2.7K HD Video Camera || B013U0F6EQ
H456 Abb Industrial Robot Mechanical Arm || B01M9DQUAS
Kohstar S520 4th generation robot lawn mower || B06WD7MT8W
LEGO 31313 Mindstorms Programmable EV3 Customizable Robot with Sensors || B00BMKLVJ6
LEGO Creator Robo Explorer 31062 Building Kit || B01KJEO7TQ
                      Miposaur || B00VFZDOC0
          OWI Robotic Arm Edge || B0017OFRCY
OWI Salt Water Fuel Cell Giant Arachnoid Kit || B007V5YYWM
Snov Surveillance Moving Robot || B01G7CEBDG
Sphero Ollie Darkside App-Controlled Robot || B00W4Z8DRQ
Sphero SPRK+ STEAM Educational Robot || B01GZ1S7OS
   Sphero Star Wars BB-8 Droid || B0107H5FJ6
Telebrands,Robo Stir Automatic Pot Stirer, As Seen On Tv Clamshell || B004PZ7FPY
       Traxxas Aton Quadcopter || B019OQEIPI
    WowWee - MiP the Toy Robot || B00KMSOIGM
Yipa 3D Flip Mini RC Drone with LED Flash Light 29mm 2.4G 4CH 6 Axis Gyro CX-10 UFO Quadcopter || B01NARDYUQ
Zodiac MX6 Automatic In Ground Pool Cleaner || B00IG9LZ4C
        eDrawBot Drawing Robot || B06XC7G3JL
iRobot Roomba 650 Robotic Vacuum Cleaner || B008LX6OC6
_________________________________________________________________
Do you want to search for the product by name or ASIN (ID#)? ASIN
Please enter ASIN number of the robot: B06WD7MT8W
Information of robot Kohstar S520 4th generation robot lawn mower
- ASIN: B06WD7MT8W
- Price: 1299.00
- Manufacture: Kohstar
- Purpose: Lawn mower
- User: adult
- Weight: 88.2
- Rating: 0.0
- Quantity: 25

Do you want to purchase this product? yes
Adding Kohstar S520 4th generation robot lawn mower to your order.
Do you want to search for another product? no
The product is your added to your order list.

Chose your shipping method:
    O - Over night ($10.99)
    R - Rush ($6.99)
    S - Standard ($3.99)
s


Please enter your purchase information: 
First name: Bob
Last name: Smith
Street address: 123 Cherry Ln.
City: Utopia
State: TO
Zip: 77777
Viewing Purchase:
---------------------------------------------------
Order number: 1003
Item 1: Kohstar S520 4th generation robot lawn mower
Price: $1299.0
Order time: Thu Jul 27 23:13:31 2017
Shipping option: Standard shipping  Shipped yet: No
Price before tax and handling: $1299.00
Tax: $116.91
Shipping fee: $3.99
Total price: $1420.26
---------------------------------------------------

Inserting Order #1003. Heap size: 3
Returning to Main Menu.

========================= Main Menu ==========================
Please type C for customer, E for employee, or type Q to quit.
e
Welcome to the employee control panel!

Options:
1. View Orders by Priority
2. Ship an Order
3. List Database of Products
-List data sorted by primary key
-List data sorted by secondary key
4. Add New Robot
5. Remove Robot
6. Search for a Customer
7. List all Customers
8. Exit Employee Menu

Please chose an option between 1 and 8: 1
Printing orders:
---------------------------------------------------
Order number: 1001
Item 1: 4M Smart Robot
Price: $10.89
Order time: Thu Jul 27 23:11:22 2017
Shipping option: Overnight shipping  Shipped yet: No
Price before tax and handling: $10.89
Tax: $0.98
Shipping fee: $10.99
Total price: $23.85
---------------------------------------------------

---------------------------------------------------
Order number: 1002
Item 1: iRobot Roomba 650 Robotic Vacuum Cleaner
Price: $299.99
Order time: Thu Jul 27 23:12:43 2017
Shipping option: Rush shipping  Shipped yet: No
Price before tax and handling: $299.99
Tax: $27.00
Shipping fee: $6.99
Total price: $334.61
---------------------------------------------------

---------------------------------------------------
Order number: 1003
Item 1: Kohstar S520 4th generation robot lawn mower
Price: $1299.00
Order time: Thu Jul 27 23:13:31 2017
Shipping option: Standard shipping  Shipped yet: No
Price before tax and handling: $1299.00
Tax: $116.91
Shipping fee: $3.99
Total price: $1420.26
---------------------------------------------------

Do you want to chose another option? yes


Options:
1. View Orders by Priority
2. Ship an Order
3. List Database of Products
-List data sorted by primary key
-List data sorted by secondary key
4. Add New Robot
5. Remove Robot
6. Search for a Customer
7. List all Customers
8. Exit Employee Menu

Please chose an option between 1 and 8: 2
Shipping order: 
---------------------------------------------------
Order number: 1001
Item 1: 4M Smart Robot
Price: $10.89
Order time: Thu Jul 27 23:11:22 2017
Shipping option: Overnight shipping  Shipped yet: No
Price before tax and handling: $10.89
Tax: $0.98
Shipping fee: $10.99
Total price: $23.85
---------------------------------------------------


The order has been shipped!
Do you want to chose another option? yes


Options:
1. View Orders by Priority
2. Ship an Order
3. List Database of Products
-List data sorted by primary key
-List data sorted by secondary key
4. Add New Robot
5. Remove Robot
6. Search for a Customer
7. List all Customers
8. Exit Employee Menu

Please chose an option between 1 and 8: 1
Printing orders:
---------------------------------------------------
Order number: 1002
Item 1: iRobot Roomba 650 Robotic Vacuum Cleaner
Price: $299.99
Order time: Thu Jul 27 23:12:43 2017
Shipping option: Rush shipping  Shipped yet: No
Price before tax and handling: $299.99
Tax: $27.00
Shipping fee: $6.99
Total price: $334.61
---------------------------------------------------

---------------------------------------------------
Order number: 1003
Item 1: Kohstar S520 4th generation robot lawn mower
Price: $1299.00
Order time: Thu Jul 27 23:13:31 2017
Shipping option: Standard shipping  Shipped yet: No
Price before tax and handling: $1299.00
Tax: $116.91
Shipping fee: $3.99
Total price: $1420.26
---------------------------------------------------

---------------------------------------------------
Order number: 1001
Item 1: 4M Smart Robot
Price: $10.89
Order time: Thu Jul 27 23:11:22 2017
Shipping option: Overnight shipping  Shipped yet: No
Price before tax and handling: $10.89
Tax: $0.98
Shipping fee: $10.99
Total price: $23.85
---------------------------------------------------

Do you want to chose another option? yes


Options:
1. View Orders by Priority
2. Ship an Order
3. List Database of Products
-List data sorted by primary key
-List data sorted by secondary key
4. Add New Robot
5. Remove Robot
6. Search for a Customer
7. List all Customers
8. Exit Employee Menu

Please chose an option between 1 and 8: 4
Adding a new robot. Please enter the specified information:

Name: SuperRobot 500
.ASIN (like an ID number): 99999999
Price (in USD): 99.50
Manufacturer: Me
Purpose of this robot: 
This robot makes waffles.
Who is the intended audience of this robot?
ex: everyone, adults, children
everyone
Weight (lbs): 10
Average User Rating (0-5): 5
Inserting SuperRobot 500...
Do you want to chose another option? no


========================= Main Menu ==========================
Please type C for customer, E for employee, or type Q to quit.
q
Writing data to outputFile.txt.
Thank you for shopping at our store.
Have a great day!!!

          ________
     _,.-Y  |  |  Y-._
    .-~"   ||  |  |  |   "-.
    I" ""=="|" !""! "|"[]""|     _____
    L__  [] |..------|:   _[----I" .-{"-.
   I___|  ..| l______|l_ [__L]_[I_/r(=}=-P
  [L______L_[________]______j~  '-=c_]/=-^
    \_I_j.--.\==I|I==_/.--L_]
    [_((==)[`-----"](==)j
    I--I"~~"""~~"I--I
    |[]|         |[]|
    l__j  KATHY  l__j
    |!!|  BINLEI |!!|
    |..| STEPHEN |..|
    ([])    MY   ([])
    ]--[   LUCY  ]--[
    [_L]         [_L]  
   /|..|\       /|..|\
  `=}--{='     `=}--{='
 .-^--r-^-.   .-^--r-^-.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

```
