"""
To run this script:
	python shoppingCost.py

In order to pass the autograder your createPricesDict function should
return a dictionary like this:
{'Bananas': 1.56,
 'French fried potatoes': 2.61,
 ...
}
If you run the above script, a correct calculateShoppingCost function should return:

The final cost for our shopping cart is 35.58
"""

import csv

def calculateShoppingCost(productPrices, shoppingCart):
	finalCost = 0
	"*** Add your code in here ***"
	for key in shoppingCart:
		price = productPrices.get(key)
		number = shoppingCart.get(key)
		finalCost += float(price) * float(number)
	return finalCost


def createPricesDict(filename):
	productPrice = {}
	"*** Add your code in here ***"
	f = open(filename)
	reader = csv.reader(f)
	for row in reader:
		productPrice[row[0]] = row[1]
	return productPrice


if __name__ == '__main__':
	prices = createPricesDict("Grocery.csv")
	myCart = {"Bacon": 2,
		      "Homogenized milk": 1,
		      "Eggs": 5}
	print("The final cost for our shopping cart is {}".format(calculateShoppingCost(prices, myCart)))
