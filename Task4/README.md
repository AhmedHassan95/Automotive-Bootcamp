## Requirements:

ATM Banking Application

## Steps:

1. Welcoming messages

2. Take the user inputs:
	- Card holder Name
	- Primary account Number
	- Card Expiration Date
	
3. Take the terminal inputs:
   	- Transaction Amount
	- Transaction Date
	- Maximum Amount for each transaction per day
	
4. Check if the Card is expired or not:
   	- Expired: Reject the transaction 
	- Not Expired: Continue the process

5. Check if the amount is less than the Maximum Amount per day or not:
	- Amount is less than the Maximum Amount per day: Continue the process  
	- Amount is larger than the Maximum Amount per day: Reject the transaction 
	
6. Check if the Card is stored in the system or not:
	- Card Found: Continue the process 
	- Card Not Found: Reject the transaction 	

7. Check if the amount is less than the balance or not:
	- Balance is larger than or equal: Accept the transaction 
	- Balance is less than amount: Reject the transaction 
