# Assignment 1: ESP Cinema

## Learning Goals
Data types, Arrays, Operators, Branches, Loops, Input/Output, Functions, Constants

**Note:** Pointers or Structs are allowed as well, but don't panic: they are **not** required. :)

**Note:** Not complying with any of the learning goals will lead to a severe point deduction!

## Specification
Some general specifications must be followed for every assignment in this course. A list of these specifications can be
found here: [Assessment of Assignments - Deductions](https://www.notion.so/coding-tugraz/Assessment-of-Assignments-How-do-you-get-your-points-d7cca6cc89a344e38ad74dd3ccb73cb3?pvs=4#e3203e50b1fc4ba787bdbf5fb46262ae).
Please follow these specifications to avoid point deductions. As memory management is not relevant for this assignment,
you can mostly ignore this section within the specifications.

### Allowed Libraries
In general, all C standard libraries are allowed, but definitely not required.

## Submission
* File: a1.c
* **Deadline:** 26.03.2025, 23:59 CET

## Grading

| Category	    | Points | 
|---------------|--------|
| Functionality | 8.4    |
| Code Quality  | 3.6    |
|               | 12     |

More detailed information can be found in the [grading scheme](https://coding-tugraz.notion.site/Assessment-of-Assignments-How-do-you-get-your-points-d7cca6cc89a344e38ad74dd3ccb73cb3). 

---

## ESP Cinema
A cinema in Graz asks you to write a text-based software for their customers (since they have heard that you study programming at TU Graz).

The software should be able to calculate the final prices for combinations of a chosen movie with some optional treats after applying a discount.

Furthermore, the program should recommend some movie (should be able to propose suitable combinations) based on a budget provided by the customer.
## General

**Important: Each time the program waits for an input, the following needs to be printed in a separate line: ` > `<br>**
**We call this "command prompt"**

Currently, we are offering the following **movies**:
- "Truth seeking at TU Graz" for 3.50€
- "Flow" for 59.75€
- "The Hitchhiker’s Guide to the Galaxy"  for 77.42€
- "The Place" for 43.30€
- "Highway to Hell ESP Edition" for 92.10€
- "Interstate 60" for 28.00€

In addition to a purchase of a movie ticket, a customer can decide to buy some **popcorn and/or a drink**:
- Popcorn tastes:
 Salted Popcorn (3.50€), Spicy Popcorn (9.99€), Caramel Popcorn (5.50€), Cheese Popcorn (7.80€).
- Available drinks:
Cola (2.10€), Sprite (2.00€), Orange Juice (2.95€), Water (1.10€), Ice Tea (2.60€).

Per customer <u>only one popcorn plus one drink at most</u> can be served in total - this is a 100% economically justified decision and has nothing to do with making the task simpler for our programmer! ;)

Additionally, the cinema offers a **30% discount to students**.
Participants of the cinema's **membership program get 15% discount** upon showing a corresponding card at the checkout.

**Important:** Both discounts are only applicable to movie tickets, not the treats!
Only one of two discounts (namely the larger one) can be applied at a time.

Here are the requirements your final software has to fulfill (according to the cinema manager who has hired you):

<u>**Important**: Each number must be rounded to 2 decimal places when it comes to an output!</u>

1. In the beginning, the program prints out a standard text<br>
`\n=== Welcome to Cinema Booking System ===\n\nToday in our cinema:\n`, followed by all currently running movies including their prices. Additionally, there should be a reference to the so called Recommender Mode in the end, even if it is not implemented!<br>
The list of movies should be <u>sorted descending by the price</u> -> The most expensive film should be shown first (since studies show that customers tend to go for the first option on the list more often than the other ones).<br>
Furthermore, there should be a hint that the user should be able to quit the application by entering 0.

2. Then it prompts customer to choose a movie from the previously listed options (1-6) -> this should lead to the so called Purchase Mode.<br>
The Recommender Mode (7) is an alternative way of proceeding if the customer has no particular movie in mind yet.<br>
The Recommender Mode is just a nice addition to the main functionality of a program, so please focus on the Purchase Mode first!

(See examples in following sections!).

### Exit
By entering 0, the application should terminate. It should print the message `Thanks for your visit! Looking forward to seeing you again!\n` and return the value `0` to the system.

#### Example Exit
```

=== Welcome to Cinema Booking System ===

Today in our cinema:
1. Highway to Hell ESP Edition - €92.10
2. The Hitchhiker’s Guide to the Galaxy - €77.42
3. Flow - €59.75
4. The Place - €43.30
5. Interstate 60 - €28.00
6. Truth seeking at TU Graz - €3.50

What do you want?:
- leave (enter 0)
- to proceed choosing a movie on your own (enter 1-6)
- to be recommended some movie-treats-combos according to your budget (enter 7)
 > 0
Thanks for your visit! Looking forward to seeing you again!
```

### Purchase mode

The execution of the program has to follow these steps:
1. If customer has chosen a movie (has entered 1-6 before),  your program should ask them, whether they are a student.<br>
If no -> ask customer whether they own a membership card.
2. The program should ask customer whether they want to add treats (popcorn and/or a drink) to the purchase.<br>
If yes -> Ask customer what exactly they want to have and list prices (again in descending order).
5. Print an invoice with detailed description of the purchase.<br>
Consider and include a student or membership discount and treats! In case nothing was applied or added to the order, print nothing for an unused category of add-ons. Finally, wish the customer a lot of fun (since we want to pretend that we value our customers)!

The program should terminate with the value `1`.

#### Examples Purchase Mode
Example with no discount but popcorn + drink:
```

=== Welcome to Cinema Booking System ===

Today in our cinema:
1. Highway to Hell ESP Edition - €92.10
2. The Hitchhiker’s Guide to the Galaxy - €77.42
3. Flow - €59.75
4. The Place - €43.30
5. Interstate 60 - €28.00
6. Truth seeking at TU Graz - €3.50

What do you want?:
- leave (enter 0)
- to proceed choosing a movie on your own (enter 1-6)
- to be recommended some movie-treats-combos according to your budget (enter 7)
 > 4

Chosen Film: The Place

Are you a student? (enter y for "Yes", n for "No")
 > n

Do you have a membership card? (enter y for "Yes", n for "No")
 > n

Would you like some popcorn? (enter y for "Yes", n for "No")
 > y

Our popcorn flavors:
1. Spicy Popcorn - €9.99
2. Cheese Popcorn - €7.80
3. Caramel Popcorn - €5.50
4. Salted Popcorn - €3.50
Select an option (1-4)
 > 2

Would you like a drink? (enter y for "Yes", n for "No")
 > y

Our available drinks:
1. Orange Juice - €2.95
2. Ice Tea - €2.60
3. Cola - €2.10
4. Sprite - €2.00
5. Water - €1.10
Select an option (1-5)
 > 1

=== Your Receipt ===
Movie: The Place
Ticket price: €43.30
Popcorn (Cheese Popcorn): €7.80
Drink (Orange Juice): €2.95
Total: €54.05

Congratulations on your purchase! Enjoy the movie!
```
Example with student-discount and popcorn, but no drink:
```

=== Welcome to Cinema Booking System ===

Today in our cinema:
1. Highway to Hell ESP Edition - €92.10
2. The Hitchhiker’s Guide to the Galaxy - €77.42
3. Flow - €59.75
4. The Place - €43.30
5. Interstate 60 - €28.00
6. Truth seeking at TU Graz - €3.50

What do you want?:
- leave (enter 0)
- to proceed choosing a movie on your own (enter 1-6)
- to be recommended some movie-treats-combos according to your budget (enter 7)
 > 1

Chosen Film: Highway to Hell ESP Edition

Are you a student? (enter y for "Yes", n for "No")
 > y

Would you like some popcorn? (enter y for "Yes", n for "No")
 > y

Our popcorn flavors:
1. Spicy Popcorn - €9.99
2. Cheese Popcorn - €7.80
3. Caramel Popcorn - €5.50
4. Salted Popcorn - €3.50
Select an option (1-4)
 > 4

Would you like a drink? (enter y for "Yes", n for "No")
 > n

=== Your Receipt ===
Movie: Highway to Hell ESP Edition
Ticket price: €92.10
Applicable discount: €-27.63
Popcorn (Salted Popcorn): €3.50
Total: €67.97

Congratulations on your purchase! Enjoy the movie!
```

### Recommender mode
Additionally, we want to have a recommender system (but this is not as important as the Purchase Mode, so please focus on Purchase Mode first!)

At first, the customer is asked whether they are a student or whether they own a membership card.<br>
(Based on that, the prices are gonna be updated later on).

The customer should be able to enter some budget that they are willing to invest in a movie experience today. Based on that, we want to print out all possible combinations consisting of a Movie + Treats. For this you also have to take into account a potential discount (student or membership).<br>
**The output should be sorted descending by prices, with the most expensive combinations being displayed first**!

If the program finds some suitable combinations, it should terminate with the return value `2`.<br>
Otherwise (if no such combinations were found), it is supposed to terminate with `-1`.

**Hint:** Anyone who doesn't honor the cent isn't worth the euro!<br>
**Hint 2:** We do no error-checks for the budget-<u>input</u>!

#### Examples Recommender Mode
Example with membership-discount and 50€ as budget:
```

=== Welcome to Cinema Booking System ===

Today in our cinema:
1. Highway to Hell ESP Edition - €92.10
2. The Hitchhiker’s Guide to the Galaxy - €77.42
3. Flow - €59.75
4. The Place - €43.30
5. Interstate 60 - €28.00
6. Truth seeking at TU Graz - €3.50

What do you want?:
- leave (enter 0)
- to proceed choosing a movie on your own (enter 1-6)
- to be recommended some movie-treats-combos according to your budget (enter 7)
 > 7

Welcome to the recommender system!

What's your budget in €?
 > 50

Are you a student? (enter y for "Yes", n for "No")
 > n

Do you have a membership card? (enter y for "Yes", n for "No")
 > y

Recommended movies within your budget (€50.00):
- Movie "The Place" + Spicy Popcorn + Orange Juice (€49.75)
- Movie "The Place" + Spicy Popcorn + Ice Tea (€49.39)
- Movie "The Place" + Spicy Popcorn + Cola (€48.89)
- Movie "The Place" + Spicy Popcorn + Sprite (€48.80)
- Movie "The Place" + Spicy Popcorn + Water (€47.89)
- Movie "The Place" + Cheese Popcorn + Orange Juice (€47.55)
- Movie "The Place" + Cheese Popcorn + Ice Tea (€47.20)
- Movie "The Place" + Cheese Popcorn + Cola (€46.70)
- Movie "The Place" + Cheese Popcorn + Sprite (€46.61)
- Movie "The Place" + Cheese Popcorn + Water (€45.70)
- Movie "The Place" + Caramel Popcorn + Orange Juice (€45.25)
- Movie "The Place" + Caramel Popcorn + Ice Tea (€44.91)
- Movie "The Place" + Caramel Popcorn + Cola (€44.41)
- Movie "The Place" + Caramel Popcorn + Sprite (€44.30)
- Movie "The Place" + Caramel Popcorn + Water (€43.41)
- Movie "The Place" + Salted Popcorn + Orange Juice (€43.26)
- Movie "The Place" + Salted Popcorn + Ice Tea (€42.91)
- Movie "The Place" + Salted Popcorn + Cola (€42.41)
- Movie "The Place" + Salted Popcorn + Sprite (€42.30)
- Movie "The Place" + Salted Popcorn + Water (€41.41)
- Movie "Interstate 60" + Spicy Popcorn + Orange Juice (€36.74)
- Movie "Interstate 60" + Spicy Popcorn + Ice Tea (€36.39)
- Movie "Interstate 60" + Spicy Popcorn + Cola (€35.89)
- Movie "Interstate 60" + Spicy Popcorn + Sprite (€35.79)
- Movie "Interstate 60" + Spicy Popcorn + Water (€34.89)
- Movie "Interstate 60" + Cheese Popcorn + Orange Juice (€34.55)
- Movie "Interstate 60" + Cheese Popcorn + Ice Tea (€34.20)
- Movie "Interstate 60" + Cheese Popcorn + Cola (€33.70)
- Movie "Interstate 60" + Cheese Popcorn + Sprite (€33.60)
- Movie "Interstate 60" + Cheese Popcorn + Water (€32.70)
- Movie "Interstate 60" + Caramel Popcorn + Orange Juice (€32.25)
- Movie "Interstate 60" + Caramel Popcorn + Ice Tea (€31.90)
- Movie "Interstate 60" + Caramel Popcorn + Cola (€31.40)
- Movie "Interstate 60" + Caramel Popcorn + Sprite (€31.30)
- Movie "Interstate 60" + Caramel Popcorn + Water (€30.40)
- Movie "Interstate 60" + Salted Popcorn + Orange Juice (€30.25)
- Movie "Interstate 60" + Salted Popcorn + Ice Tea (€29.90)
- Movie "Interstate 60" + Salted Popcorn + Cola (€29.40)
- Movie "Interstate 60" + Salted Popcorn + Sprite (€29.30)
- Movie "Interstate 60" + Salted Popcorn + Water (€28.40)
- Movie "Truth seeking at TU Graz" + Spicy Popcorn + Orange Juice (€15.92)
- Movie "Truth seeking at TU Graz" + Spicy Popcorn + Ice Tea (€15.56)
- Movie "Truth seeking at TU Graz" + Spicy Popcorn + Cola (€15.06)
- Movie "Truth seeking at TU Graz" + Spicy Popcorn + Sprite (€14.96)
- Movie "Truth seeking at TU Graz" + Spicy Popcorn + Water (€14.06)
- Movie "Truth seeking at TU Graz" + Cheese Popcorn + Orange Juice (€13.72)
- Movie "Truth seeking at TU Graz" + Cheese Popcorn + Ice Tea (€13.38)
- Movie "Truth seeking at TU Graz" + Cheese Popcorn + Cola (€12.88)
- Movie "Truth seeking at TU Graz" + Cheese Popcorn + Sprite (€12.78)
- Movie "Truth seeking at TU Graz" + Cheese Popcorn + Water (€11.88)
- Movie "Truth seeking at TU Graz" + Caramel Popcorn + Orange Juice (€11.42)
- Movie "Truth seeking at TU Graz" + Caramel Popcorn + Ice Tea (€11.07)
- Movie "Truth seeking at TU Graz" + Caramel Popcorn + Cola (€10.57)
- Movie "Truth seeking at TU Graz" + Caramel Popcorn + Sprite (€10.47)
- Movie "Truth seeking at TU Graz" + Caramel Popcorn + Water (€9.57)
- Movie "Truth seeking at TU Graz" + Salted Popcorn + Orange Juice (€9.43)
- Movie "Truth seeking at TU Graz" + Salted Popcorn + Ice Tea (€9.07)
- Movie "Truth seeking at TU Graz" + Salted Popcorn + Cola (€8.57)
- Movie "Truth seeking at TU Graz" + Salted Popcorn + Sprite (€8.47)
- Movie "Truth seeking at TU Graz" + Salted Popcorn + Water (€7.57)
```
Example with no discount and 50€ budget:
```

=== Welcome to Cinema Booking System ===

Today in our cinema:
1. Highway to Hell ESP Edition - €92.10
2. The Hitchhiker’s Guide to the Galaxy - €77.42
3. Flow - €59.75
4. The Place - €43.30
5. Interstate 60 - €28.00
6. Truth seeking at TU Graz - €3.50

What do you want?:
- leave (enter 0)
- to proceed choosing a movie on your own (enter 1-6)
- to be recommended some movie-treats-combos according to your budget (enter 7)
 > 7

Welcome to the recommender system!

What's your budget in €?
 > 50

Are you a student? (enter y for "Yes", n for "No")
 > n

Do you have a membership card? (enter y for "Yes", n for "No")
 > n

Recommended movies within your budget (€50.00):
- Movie "The Place" + Caramel Popcorn + Water (€49.90)
- Movie "The Place" + Salted Popcorn + Orange Juice (€49.75)
- Movie "The Place" + Salted Popcorn + Ice Tea (€49.40)
- Movie "The Place" + Salted Popcorn + Cola (€48.90)
- Movie "The Place" + Salted Popcorn + Sprite (€48.80)
- Movie "The Place" + Salted Popcorn + Water (€47.90)
- Movie "Interstate 60" + Spicy Popcorn + Orange Juice (€40.94)
- Movie "Interstate 60" + Spicy Popcorn + Ice Tea (€40.59)
- Movie "Interstate 60" + Spicy Popcorn + Cola (€40.09)
- Movie "Interstate 60" + Spicy Popcorn + Sprite (€39.99)
- Movie "Interstate 60" + Spicy Popcorn + Water (€39.09)
- Movie "Interstate 60" + Cheese Popcorn + Orange Juice (€38.75)
- Movie "Interstate 60" + Cheese Popcorn + Ice Tea (€38.40)
- Movie "Interstate 60" + Cheese Popcorn + Cola (€37.90)
- Movie "Interstate 60" + Cheese Popcorn + Sprite (€37.80)
- Movie "Interstate 60" + Cheese Popcorn + Water (€36.90)
- Movie "Interstate 60" + Caramel Popcorn + Orange Juice (€36.45)
- Movie "Interstate 60" + Caramel Popcorn + Ice Tea (€36.10)
- Movie "Interstate 60" + Caramel Popcorn + Cola (€35.60)
- Movie "Interstate 60" + Caramel Popcorn + Sprite (€35.50)
- Movie "Interstate 60" + Caramel Popcorn + Water (€34.60)
- Movie "Interstate 60" + Salted Popcorn + Orange Juice (€34.45)
- Movie "Interstate 60" + Salted Popcorn + Ice Tea (€34.10)
- Movie "Interstate 60" + Salted Popcorn + Cola (€33.60)
- Movie "Interstate 60" + Salted Popcorn + Sprite (€33.50)
- Movie "Interstate 60" + Salted Popcorn + Water (€32.60)
- Movie "Truth seeking at TU Graz" + Spicy Popcorn + Orange Juice (€16.44)
- Movie "Truth seeking at TU Graz" + Spicy Popcorn + Ice Tea (€16.09)
- Movie "Truth seeking at TU Graz" + Spicy Popcorn + Cola (€15.59)
- Movie "Truth seeking at TU Graz" + Spicy Popcorn + Sprite (€15.49)
- Movie "Truth seeking at TU Graz" + Spicy Popcorn + Water (€14.59)
- Movie "Truth seeking at TU Graz" + Cheese Popcorn + Orange Juice (€14.25)
- Movie "Truth seeking at TU Graz" + Cheese Popcorn + Ice Tea (€13.90)
- Movie "Truth seeking at TU Graz" + Cheese Popcorn + Cola (€13.40)
- Movie "Truth seeking at TU Graz" + Cheese Popcorn + Sprite (€13.30)
- Movie "Truth seeking at TU Graz" + Cheese Popcorn + Water (€12.40)
- Movie "Truth seeking at TU Graz" + Caramel Popcorn + Orange Juice (€11.95)
- Movie "Truth seeking at TU Graz" + Caramel Popcorn + Ice Tea (€11.60)
- Movie "Truth seeking at TU Graz" + Caramel Popcorn + Cola (€11.10)
- Movie "Truth seeking at TU Graz" + Caramel Popcorn + Sprite (€11.00)
- Movie "Truth seeking at TU Graz" + Caramel Popcorn + Water (€10.10)
- Movie "Truth seeking at TU Graz" + Salted Popcorn + Orange Juice (€9.95)
- Movie "Truth seeking at TU Graz" + Salted Popcorn + Ice Tea (€9.60)
- Movie "Truth seeking at TU Graz" + Salted Popcorn + Cola (€9.10)
- Movie "Truth seeking at TU Graz" + Salted Popcorn + Sprite (€9.00)
- Movie "Truth seeking at TU Graz" + Salted Popcorn + Water (€8.10)
```

---

## Error Messages

- If the customer is asked to enter a number and the entered number does not lie in the demanded interval, the program should print `Invalid input. Please enter number in [<FROM>, <TO>]!\n > ` and ask for input again.

- If the customer is asked to enter a char and the entered char does not lie in the demanded interval, the program should print `Invalid input. Please enter either y for "Yes" or n for "No"\n > ` and ask for input again.

- If the recommender does not find any suitable combination (e.g. when the budget entered by the customer was too small), it should print `Sorry, we have no offers within your budget (<BUDGET>)!` and terminate with `-1`.

### Examples Error Messages
Purchase Mode:
```

=== Welcome to Cinema Booking System ===

Today in our cinema:
1. Highway to Hell ESP Edition - €92.10
2. The Hitchhiker’s Guide to the Galaxy - €77.42
3. Flow - €59.75
4. The Place - €43.30
5. Interstate 60 - €28.00
6. Truth seeking at TU Graz - €3.50

What do you want?:
- leave (enter 0)
- to proceed choosing a movie on your own (enter 1-6)
- to be recommended some movie-treats-combos according to your budget (enter 7)
 > 8
Invalid input. Please enter number in [0, 7]!
 > ab
Invalid input. Please enter number in [0, 7]!
 > 4

Chosen Film: The Place

Are you a student? (enter y for "Yes", n for "No")
 > z
Invalid input. Please enter either y for "Yes" or n for "No"
 > 123
Invalid input. Please enter either y for "Yes" or n for "No"
 > yy
Invalid input. Please enter either y for "Yes" or n for "No"
 > y

Would you like some popcorn? (enter y for "Yes", n for "No")
 > 1
Invalid input. Please enter either y for "Yes" or n for "No"
 > ab
Invalid input. Please enter either y for "Yes" or n for "No"
 > nn
Invalid input. Please enter either y for "Yes" or n for "No"
 > n

Would you like a drink? (enter y for "Yes", n for "No")
 > n

=== Your Receipt ===
Movie: The Place
Ticket price: €43.30
Applicable discount: €-12.99
Total: €30.31

Congratulations on your purchase! Enjoy the movie!
```
Recommender Mode:
```

=== Welcome to Cinema Booking System ===

Today in our cinema:
1. Highway to Hell ESP Edition - €92.10
2. The Hitchhiker’s Guide to the Galaxy - €77.42
3. Flow - €59.75
4. The Place - €43.30
5. Interstate 60 - €28.00
6. Truth seeking at TU Graz - €3.50

What do you want?:
- leave (enter 0)
- to proceed choosing a movie on your own (enter 1-6)
- to be recommended some movie-treats-combos according to your budget (enter 7)
 > 9
Invalid input. Please enter number in [0, 7]!
 > ab
Invalid input. Please enter number in [0, 7]!
 > 7

Welcome to the recommender system!

What's your budget in €?
 > 3

Are you a student? (enter y for "Yes", n for "No")
 > yy
Invalid input. Please enter either y for "Yes" or n for "No"
 > y

Recommended movies within your budget (€3.00):
Sorry, we have no offers within your budget (€3.00)!
```

---

## Hints ;)
1. You can use any data structure that works for you, but keep things simple!<br>
No structs or pointers are required at all!<br>
2. Do not think too much about the sorting itself - no sorting function is necessary at all for this assignment!
3. We are a serious cinema and do not want to cheat our customers! Therefore we want to have the highest precision in our calculations!
3. If something is unclear, try to read and understand the examples! They might be more helpful than any description!
4. **We have public testcases in this course and a tool which executes the tests for you! The output must look EXACTLY as in the provided testcases for you to get points!<br>So do not miss this fact and run `make test` as soon as possible to verify output of your program!**
