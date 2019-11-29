default:
	gcc -o dsatur src/* -lm
	./dsatur
	cat output.csv

build:
	rm AD_JoseHenrique2090341_HeitorVentura2086883.zip
	zip -r AD_JoseHenrique2090341_HeitorVentura2086883.zip ./ -x "*.git*" "*.vscode*" "*samples*"
