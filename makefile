compile:
	gcc -o dist/a.out $(C)

hello:
	@echo "Hi, BOB!"

start:
	gcc -o dist/a.out $(C)
	./dist/a.out
