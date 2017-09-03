/*
 * youtube.c
 *
 * Created: 2017-09-02 오후 11:35:00
 * Author : zanywhale
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// util
void on(int a){
	switch(a){
		break;
		case 1:
		PORTA = PORTA|0b1;
		break;
		case 2:
		PORTA = PORTA|0b10;
		break;
		case 3:
		PORTA = PORTA|0b100;
		break;
		case 4:
		PORTA = PORTA|0b1000;
		break;
		case 5:
		PORTA = PORTA|0b10000;
		break;
		case 6:
		PORTA = PORTA|0b100000;
		break;
		case 7:
		PORTA = PORTA|0b1000000;
		break;
		case 8:
		PORTA = PORTA|0b10000000;
		break;
		case 9:
		PORTD = PORTD|0b1;
		break;
		case 10:
		PORTD = PORTD|0b10;
		break;
		case 11:
		PORTD = PORTD|0b100;
		break;
		case 12:
		PORTD = PORTD|0b1000;
		break;
		case 13:
		PORTD = PORTD|0b10000;
		break;
		case 14:
		PORTD = PORTD|0b100000;
		break;
		case 15:
		PORTD = PORTD|0b1000000;
		break;
		case 16:
		PORTD = PORTD|0b10000000;
	}
}
void off(int a){
	switch(a){
		break;
		case 1:
		PORTA = PORTA^0b1;
		break;
		case 2:
		PORTA = PORTA^0b10;
		break;
		case 3:
		PORTA = PORTA^0b100;
		break;
		case 4:
		PORTA = PORTA^0b1000;
		break;
		case 5:
		PORTA = PORTA^0b10000;
		break;
		case 6:
		PORTA = PORTA^0b100000;
		break;
		case 7:
		PORTA = PORTA^0b1000000;
		break;
		case 8:
		PORTA = PORTA^0b10000000;
		break;
		case 9:
		PORTD = PORTD^0b1;
		break;
		case 10:
		PORTD = PORTD^0b10;
		break;
		case 11:
		PORTD = PORTD^0b100;
		break;
		case 12:
		PORTD = PORTD^0b1000;
		break;
		case 13:
		PORTD = PORTD^0b10000;
		break;
		case 14:
		PORTD = PORTD^0b100000;
		break;
		case 15:
		PORTD = PORTD^0b1000000;
		break;
		case 16:
		PORTD = PORTD^0b10000000;
	}
}
void all_off(){
	PORTA = 0x00;
	PORTD = 0x00;
}
void all_on(){
	PORTA = 0xff;
	PORTD = 0xff;
}
void wait(){
	_delay_ms(500);
}

// matrix
void first(){
	// 1
	on(1);
	wait();

	// 2
	on(1); on(5);
	wait();

	// 3
	off(1);
	on(5); on(9);
	wait();

	// 4
	off(5);
	on(9); on(13);
	wait();
	wait();
}
void second(){
	// 1
	on(2); on(3);
	wait();

	// 2
	off(3);
	on(6); on(7);
	wait();

	// 3
	off(2); off(7);
	on(10); on(11);
	wait();

	// 4
	off(6); off(11);
	on(14); on(15);
	wait();
	wait();
}
void third(){
	// 1
	on(1); on(2);
	wait();

	// 2
	off(2);
	on(5); on(6);
	_delay_ms(300);

	// 3
	off(1); off(5);
	on(2); on(7);
	_delay_ms(300);

	// 4
	off(7);
	on(3);
	_delay_ms(300);

	// 5
	off(6);
	on(7);
	wait();

	// 6
	off(2); off(3);
	on(6); on(11);
	wait();
	wait();
}
void fourth(){
	// 1
	on(1);
	on(2);
	wait();

	// 2
	off(1);
	on(3);
	_delay_ms(300);

	// 3
	off(2);
	on(4);
	_delay_ms(300);

	// 4
	off(3);
	on(8);
	wait();

	// 5
	off(4);
	on(12);
	wait();

	// 6
	off(8);
	on(16);
	wait();
	wait();
}
void fifth(){
	int i = 0;
	for(i = 0; i < 10; i++){
		PORTD = 0x00;
		_delay_ms(100);
		PORTD = 0xff;
		_delay_ms(100);
	}
	PORTD = 0x00;
	off(6); off(7);
	on(14); on(15);
	wait();
	wait();
}
void sixth(){
	// 1
	on(2);
	wait();

	// 2
	on(1); on(6);
	wait();

	// 3
	off(1); off(2);
	on(5); on(10);
	_delay_ms(300);

	// 4
	off(5);
	on(9);
	_delay_ms(300);

	// 5
	off(6);
	on(5);
	_delay_ms(300);

	// 6
	off(10);
	on(6);
	_delay_ms(300);

	// 7
	off(5); off(6);
	on(10);
	on(13);
	wait();
	wait();

}
void seventh(){
	// 1
	on(1); on(2);
	wait();

	// 2
	on(5); on(6);
	wait();

	// 3
	off(1); off(5);
	on(3); on(7);
	_delay_ms(300);

	// 4
	off(2); off(6);
	on(4); on(8);
	_delay_ms(300);

	// 5
	off(3); off(4);
	on(11); on(12);
	wait();
	wait();
}
void eighth(){
	int i = 0;
	for(i = 0; i < 10; i++){
		off(9); off(10); off(11); off(12);
		_delay_ms(100);
		on(9); on(10); on(11); on(12);
		_delay_ms(100);
	}
	off(7); off(8); off(9); off(10);
	on(11); on(12);
	wait();
	wait();
}
void ninth(){
	// 1 
	on(2);
	wait();

	// 2
	on(1); on(6);
	wait();

	// 3
	off(1); off(2);
	on(5); on(10);
	wait();

	// 4
	off(5);
	on(9);
	wait();
	wait();
}
void tenth(){
	int i = 0;
	for(i = 0; i < 10; i++){
		off(9); off(10); off(11); off(12);
		_delay_ms(100);
		on(9); on(10); on(11); on(12);
		_delay_ms(100);
	}
	off(6); off(9); off(11); off(12);
	wait();
	wait();
}
void eleventh(){
	// 1
	on(1); on(2);
	wait();

	// 2
	off(2);
	on(5); on(6);
	_delay_ms(300);

	// 3
	off(1); off(5);
	on(2); on(7);
	_delay_ms(300);

	// 4
	off(7);
	on(3);
	_delay_ms(300);

	// 5
	off(6);
	on(7);
	wait();

	// 6
	off(2); off(3);
	on(6); on(11);
	wait();
	wait();

}
void twelfth(){
	// 1
	on(1); on(2);
	wait();

	// 2
	on(5); on(6);
	wait();
	wait();
	wait();
}


// start & end
void end();
void start(){
	int i=0;
	on(1); _delay_ms(100);
	on(2); _delay_ms(100);
	on(3); _delay_ms(100);
	on(4); _delay_ms(100);
	on(8); _delay_ms(100);
	on(7); _delay_ms(100);
	on(6); _delay_ms(100);
	on(5); _delay_ms(100);
	on(9); _delay_ms(100);
	on(10); _delay_ms(100);
	on(11); _delay_ms(100);
	on(12); _delay_ms(100);
	on(16); _delay_ms(100);
	on(15); _delay_ms(100);
	on(14); _delay_ms(100);
	on(13); _delay_ms(100);
	off(13); _delay_ms(100);
	off(14); _delay_ms(100);
	off(15); _delay_ms(100);
	off(16); _delay_ms(100);
	off(12); _delay_ms(100);
	off(11); _delay_ms(100);
	off(10); _delay_ms(100);
	off(9); _delay_ms(100);
	off(5); _delay_ms(100);
	off(6); _delay_ms(100);
	off(7); _delay_ms(100);
	off(8); _delay_ms(100);
	off(4); _delay_ms(100);
	off(3); _delay_ms(100);
	off(2); _delay_ms(100);
	off(1); _delay_ms(100);
	for(i = 0; i < 4; i++){
		all_on();
		wait();
		all_off();
		wait();
	}
}
void end(){
	int i = 0;
	for(i = 0; i < 30; i++){
		off(2); off(4); off(5); off(7);
		off(10); off(12); off(13); off(15);
		on(1); on(3); on(6); on(8);
		on(9); on(11); on(14); on(16);
		_delay_ms(50);
		off(1); off(3); off(6); off(8);
		off(9); off(11); off(14); off(16);
		on(2); on(4); on(5); on(7);
		on(10); on(12); on(13); on(15);
		_delay_ms(50);
	}
	for(i = 0; i < 4; i++){
		all_on();
		wait();
		all_off();
		wait();
	}
}
int main(void)
{
	DDRA = 0xff;
	DDRD = 0xff;
	start();
	first();
	second();
	third();
	fourth();
	fifth();
	sixth();
	seventh();
	eighth();
	ninth();
	tenth();
	eleventh();
	twelfth();
	end();

	return 0;
}
