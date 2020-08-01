CXX = g++
TARGET = main

.PHONY: all clean

all : $(TARGET)

Account.o : Account.cpp Account.h BankingCommonDecl.h String.h
	$(CXX) -c $<

AccountHandler.o : AccountHandler.cpp AccountHandler.h Account.h BankingCommonDecl.h NormalAccount.h HighCreditAccount.h String.h
	$(CXX) -c $<

main.o : main.cpp BankingCommonDecl.h AccountHandler.h
	$(CXX) -c $<

AccountArray.o : AccountArray.cpp AccountArray.h BankingCommonDecl.h
	$(CXX) -c $<

String.o : String.cpp String.h BankingCommonDecl.h
	$(CXX) -c $<
	
$(TARGET) : main.o AccountHandler.o Account.o AccountArray.o String.o
	$(CXX) -o $@ $^

clean :	
	rm *.o
	rm main
