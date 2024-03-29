#define LEDpin 13
#define USER_BUTTON 2

unsigned int timer1; // dp LED timer used to blink dp in 7-segment
unsigned int timer2; // timer used for up counter in 7-segment display

//variable to control state of 7-segment
unsigned int seven_segment_state; // 0,1,2,3,4,5,6,7,8,9
int A = 9;
int B = 6;
int C = 7;
int D = 3;
int E = 5;
int F = 10;
int G = 11;
int DP = 8;

void dp_led_control(void);
void seven_segment_control(void);
void timers(void);
void seven_segment_state_0(void) //displays 0 in a seven segment LED display
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}
void seven_segment_state_1(void) //displays 1 in a seven segment LED display
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

}
void seven_segment_state_2(void) //displays 2 in a seven segment LED display
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);

}
void seven_segment_state_3(void) //displays 3 in a seven segment LED display
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}
void seven_segment_state_4(void) //displays 4 in a seven segment LED display
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void seven_segment_state_5(void) //displays 5 in a seven segment LED display
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void seven_segment_state_6(void) //displays 6 in a seven segment LED display
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void seven_segment_state_7(void) //displays 7 in a seven segment LED display
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
void seven_segment_state_8(void) //displays 8 in a seven segment LED display
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void seven_segment_state_9(void) //displays 9 in a seven segment LED display
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void setup() //main function
{
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT); //setups pins of LED as input and output being HIGH or LOW
  pinMode(USER_BUTTON, INPUT_PULLUP); //button has an input_pullup resistor
}

void loop() //loop function that repeats the timers, dp led control, and seven segment control functions
{
  timers();
  dp_led_control();
  seven_segment_control();
}


void dp_led_control(void) //controls the decimal point LED, blinks twice in one second
{
  if (timer1 < 2.5)
    digitalWrite(DP, 0);
  else if (timer1 < 5)
    digitalWrite(DP, 1);
  else
    timer1 = 0;
}

void seven_segment_control(void) //cotnrols how and what is displayed by the seven_segment LED
{
  Serial.print(INPUT_PULLUP);
  if (digitalRead(USER_BUTTON) == 0)
  { //button is not pressed
    timer2 = 0;
  }

  if (timer2 > 10)
  {
    Serial.println(seven_segment_state);
    if (seven_segment_state < 9)
      seven_segment_state++;
    else
      seven_segment_state = 0;
    timer2 = 0;
  }

  //control the segments based on seven_segment_state

  if (seven_segment_state == 0)
    seven_segment_state_0();
  else if (seven_segment_state == 1)
    seven_segment_state_1();
  else if (seven_segment_state == 2)
    seven_segment_state_2();
  else if (seven_segment_state == 3)
    seven_segment_state_3();
  else if (seven_segment_state == 4)
    seven_segment_state_4();
  else if (seven_segment_state == 5)
    seven_segment_state_5();
  else if (seven_segment_state == 6)
    seven_segment_state_6();
  else if (seven_segment_state == 7)
    seven_segment_state_7();
  else if (seven_segment_state == 8)
    seven_segment_state_8();
  else if (seven_segment_state == 9)
    seven_segment_state_9();
}

void timers(void) //controls timers
{
  static unsigned long ms_runtime = 0;
  static int one_ms_timer = 0;

  if (millis() > ms_runtime)
  {
    ms_runtime++;
    one_ms_timer++;
  }

  if (one_ms_timer > 99)
  { // our choice for 99 gives us increments of 100 ms
    timer1++;
    timer2++;
    one_ms_timer = 0;
  }
}
