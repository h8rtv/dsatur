default:
	gcc -o dsatur src/* -lm
	./dsatur
	cat output.csv
