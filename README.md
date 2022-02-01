# Google-HashCode-2022-Practice-Problem

### Data analysis


Input data a:

	C = 3	
	Number of different ingredients = 6
	Our Score = 2 (Optimal)

Input data b:
	
	C = 5 
    Number of different ingredients = 6
    Our Score = 5 (Optimal)

Input data c:

	C = 10
	Number of different ingredients = 10
	Our Score = 5 (Optimal)

Input data d:

	C = 9368
	Number of different ingredients = 600
	Our Score = 1430
	Best known = 1802

Input data e:

	C = 4986
	Number of different ingredients = 10000
	Our Score = 1739
	Best known = 2083

Solution:
    Cases a, b, c can be solved by enumerating ingredients since there are at most 10 different ingredients (hence at most 2^11 - 1 different combinations).

Greedy approach:
	Degree of a client := number of clients that have conflicts with him

	Sort clients with respect to their degrees, then greedily construct the solution. 


