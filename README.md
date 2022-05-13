# Recycle
We saw that there was a lack of education and incentive for recycling in society. Through our survey, we found that people do wish to recycle, but most of the times, they do not because of the uncertainty of what is or is not recyclable. In class, we were informed that in the case where non-recyclable waste mixes with the recyclable waste, the majority of that will have to end up in landfills, because the non-recyclable waste contaminates the recyclable wastes (expections might exist). So, in order to solve the issue of lack of education regarding recyclable wastes, we create a program that can provide useful information about most common wastes to the users. And, we also received feedbacks that there was no incentive for users to be using our program or even recycling. We came up with scoring system, where neighbors can compete to be on top of the leaderboard by recycling the correct wastes. Our goal was to create a competitive space, because as human, we do want to be better than others.

How our program works: 
/* When you first start our program it asks whether you're a resident or a waste Collector
* 	If you pick 1 for resident you will be presented with 7 options
* 		You can pick 1 to see a list of common household items and then you can pick one of those to see if its recyclable or not
*		You can pick 2 to see your recycling score where you will need to enter your userID and password 
* 			(if you don't have one yet, you can register as a new user and start recycling)
* 		You can pick 3  to see the benefits of recycling
* 		You can pick 4 to register as a new user where you will need to enter your house number and create a password.
* 			It saves your userID and password along with your house number so you can check it later on if you want to and the Waste collector can alter it as well
* 		You can pick 5 to calculate your carbon footprint
* 			we found a formula online on how carbon footprint is calculated based on the different emissions sectors and we focused on the waste emission sector
* 			Waste : use (kg/week) * 52 * EF (kg CO2e/kg) = emissions (kg CO2e/yr)
* 		You can pick 6 to see how waste collectors calculate your recycling scores
* 		You can pick 7 if you have any other questions or concerns and here you will be presented with a way to contact professionals that will be more than happy to help you
* 	If you pick 2 for waste collector you will be prompted to enter a passkey
* 			All waste collectors have the same passkey and residents don't have access to it so only waste collectors can alter recycling scores. 
* 			It won't let you go further until you enter the passkey which is 69420   
* 			Once you enter that you have to enter some information about the resident
* 		You will be asked for their userID and house number
* 			There is a .txt file attached to this folder so open that and you will have the information you need
* 			The first column is the resident's userID so enter whichever userID you'd like
*			Second column is their recycling score which you won't need for this step
* 			Third column is their house number which you will need to enter to verify that the userID and the house number match
* 			And the last column is their password which you wont need in this step
* 		After you enter their userID and house number you will see the resident's current score 
* 		And you will be asked how you want to alter their score based on what you see on their recycling bin
* 			Enter -20 per every non-recyclables on their bin and if they only have recyclable items then they get the perfect score of 100 points
* 		Then you will see their new score
* 		You can refresh the .txt file to see the updated score or run the program again as a resident to see the new score

* Enjoy running our program! */
