#define F_CPU 11059200
#define UART_BAUD_RATE 9600
#include &lt;avr/io.h&gt;
#include &lt;util/delay.h&gt;
#include &lt;stdio.h&gt;
#include &lt;uart.h&gt;
#include &lt;lcd.h&gt;
int k = 0;

int main(void)
{
  uart_init();
  InitLCD();
  char input[12];
  DDRA=0b01000001;;
  DDRB=0xFF;
  PORTA=0b00000010;
  PORTB=0x00;
  while(1)
  {
    Cls();
    Writestring(&quot;SHOW RFID CARD&quot;);
    _delay_ms(1000);
    for(k=0;k&lt;12;k++)
    {
      input[k]=getchar();
    }
    Cls();
    for(k=0;k&lt;12;k++)
    {
      WriteDataToLCD(input[k]);
    }
    _delay_ms(500);
    if(input[0]==&#39;0&#39; &amp;&amp; input[1]==&#39;9&#39; &amp;&amp; input[2]==&#39;0&#39; &amp;&amp; input[3]==&#39;0&#39;&amp;&amp; input[4]==&#39;7&#39; &amp;&amp; input[5]==&#39;C&#39; &amp;&amp; input[6]==&#39;4&#39; &amp;&amp; input[7]==&#39;D&#39;&amp;&amp; input[8]==&#39;8&#39; &amp;&amp; input[9]==&#39;5&#39; &amp;&amp; input[10]==&#39;B&#39; &amp;&amp;input[11]==&#39;D&#39;)
    {
      Lowerline();
      Writestring(&quot;AUTHORIZED&quot;);
      _delay_ms(500);
      PORTB=0x0A;
      _delay_ms(4000);
      PORTB=0x00;
      _delay_ms(30);
      
      PORTB=0x05;
      _delay_ms(4000);
      PORTB=0x00;
    }
    else if(input[0]==&#39;0&#39; &amp;&amp; input[1]==&#39;9&#39; &amp;&amp; input[2]==&#39;0&#39; &amp;&amp;input[3]==&#39;0&#39; &amp;&amp; input[4]==&#39;7&#39; &amp;&amp; input[5]==&#39;9&#39; &amp;&amp; input[6]==&#39;6&#39; &amp;&amp;input[7]==&#39;4&#39; &amp;&amp; input[8]==&#39;0&#39; &amp;&amp; input[9]==&#39;4&#39; &amp;&amp; input[10]==&#39;1&#39;&amp;&amp; input[11]==&#39;0&#39;)
    {
      Lowerline();
      Writestring(&quot;AUTHORIZED&quot;);
      _delay_ms(500);
      PORTB=0x0A;
      _delay_ms(4000);
      PORTB=0x00;
      _delay_ms(30);
      PORTB=0x05;
      _delay_ms(4000);
      PORTB=0x00;
    }
    else if(input[0]==&#39;0&#39; &amp;&amp; input[1]==&#39;9&#39; &amp;&amp; input[2]==&#39;0&#39; &amp;&amp;input[3]==&#39;0&#39; &amp;&amp; input[4]==&#39;7&#39; &amp;&amp; input[5]==&#39;C&#39; &amp;&amp; input[6]==&#39;7&#39; &amp;&amp;input[7]==&#39;D&#39; &amp;&amp; input[8]==&#39;8&#39; &amp;&amp; input[9]==&#39;0&#39; &amp;&amp; input[10]==&#39;8&#39;&amp;&amp; input[11]==&#39;8&#39;)
    {
      Lowerline();
      Writestring(&quot;AUTHORIZED&quot;);
      _delay_ms(500);
      PORTB=0x0A;
      _delay_ms(4000);
      PORTB=0x00;
      _delay_ms(30);
      PORTB=0x05;
      _delay_ms(4000);
      PORTB=0x00;
    }
    else if(input[0]==&#39;0&#39; &amp;&amp; input[1]==&#39;9&#39; &amp;&amp; input[2]==&#39;0&#39; &amp;&amp;input[3]==&#39;0&#39; &amp;&amp; input[4]==&#39;7&#39; &amp;&amp; input[5]==&#39;A&#39; &amp;&amp; input[6]==&#39;D&#39; &amp;&amp;input[7]==&#39;2&#39; &amp;&amp; input[8]==&#39;1&#39; &amp;&amp; input[9]==&#39;F&#39; &amp;&amp; input[10]==&#39;B&#39;&amp;&amp; input[11]==&#39;E&#39;)
    {
      Lowerline();
      Writestring(&quot;AUTHORIZED&quot;);
      _delay_ms(500);
      PORTB=0x0A;
      _delay_ms(4000);
      
      PORTB=0x00;
      _delay_ms(30);
      PORTB=0x05;
      _delay_ms(4000);
      PORTB=0x00;
    }
    else
    {
      Cls();
      Writestring(&quot;CARD NOT&quot;);
      Lowerline();
      Writestring(&quot;REGISTERED&quot;);
      _delay_ms(1000);
      continue;
    }
    if(bit_is_clear(PINA,1))
    {
      PORTA=0x01;
      _delay_ms(10000);
      Cls();
      Writestring(&quot;VIEW RFID AGAIN&quot;);
      _delay_ms(500);
      Lowerline();
      for(k=0;k&lt;12;k++)
      {
        input[k]=getchar();
      }
      for(k=0;k&lt;12;k++)
      {
        WriteDataToLCD(input[k]);
      }
      _delay_ms(2000);
      if(input[0]==&#39;0&#39; &amp;&amp; input[1]==&#39;9&#39; &amp;&amp; input[2]==&#39;0&#39; &amp;&amp;input[3]==&#39;0&#39; &amp;&amp; input[4]==&#39;7&#39; &amp;&amp; input[5]==&#39;C&#39; &amp;&amp;input[6]==&#39;4&#39; &amp;&amp; input[7]==&#39;D&#39; &amp;&amp; input[8]==&#39;8&#39; &amp;&amp;input[9]==&#39;5&#39; &amp;&amp; input[10]==&#39;B&#39; &amp;&amp; input[11]==&#39;D&#39;)
      {
        Cls();
        Lowerline();
        Writestring(&quot;WELCOME MR. W&quot;);
        _delay_ms(2000);
      }
  
      else if(input[0]==&#39;0&#39; &amp;&amp; input[1]==&#39;9&#39; &amp;&amp; input[2]==&#39;0&#39; &amp;&amp;input[3]==&#39;0&#39; &amp;&amp; input[4]==&#39;7&#39; &amp;&amp; input[5]==&#39;9&#39; &amp;&amp;input[6]==&#39;6&#39; &amp;&amp; input[7]==&#39;4&#39; &amp;&amp; input[8]==&#39;0&#39; &amp;&amp;input[9]==&#39;4&#39; &amp;&amp; input[10]==&#39;1&#39; &amp;&amp; input[11]==&#39;0&#39;)
      {
      Cls();
      Lowerline();
      Writestring(&quot;WELCOME MR. X&quot;);
      _delay_ms(2000);
      }
      else if(input[0]==&#39;0&#39; &amp;&amp; input[1]==&#39;9&#39; &amp;&amp; input[2]==&#39;0&#39; &amp;&amp;input[3]==&#39;0&#39; &amp;&amp; input[4]==&#39;7&#39; &amp;&amp; input[5]==&#39;C&#39; &amp;&amp;input[6]==&#39;7&#39; &amp;&amp; input[7]==&#39;D&#39; &amp;&amp; input[8]==&#39;8&#39; &amp;&amp;input[9]==&#39;0&#39; &amp;&amp; input[10]==&#39;8&#39; &amp;&amp; input[11]==&#39;8&#39;)
      {
        Cls();
        Lowerline();
        Writestring(&quot;WELCOME MR. Y&quot;);
        _delay_ms(2000);
      }
      else if(input[0]==&#39;0&#39; &amp;&amp; input[1]==&#39;9&#39; &amp;&amp; input[2]==&#39;0&#39; &amp;&amp;input[3]==&#39;0&#39; &amp;&amp; input[4]==&#39;7&#39; &amp;&amp; input[5]==&#39;A&#39; &amp;&amp;input[6]==&#39;D&#39; &amp;&amp; input[7]==&#39;2&#39; &amp;&amp; input[8]==&#39;1&#39; &amp;&amp;input[9]==&#39;F&#39; &amp;&amp; input[10]==&#39;B&#39; &amp;&amp; input[11]==&#39;E&#39;)
      {
        Cls();
        Lowerline();
        Writestring(&quot;WELCOME MR. Z&quot;);
        _delay_ms(2000);
      }
      else
      {
        Cls();
        Writestring(&quot;UNAUTHORIZED&quot;);
        Lowerline();
        Writestring(&quot;ENTRY&quot;);
        PORTA=0b01000000;
        _delay_ms(15000);
        Writestring(&quot;Alarm Calling&quot;);
        Cls();
        printf(&quot;AT+CMGF=1%c&quot;,13);
        _delay_ms(200);
        printf(&quot;AT+CMGS=\&quot;9530135545\&quot;%c&quot;,13);
        _delay_ms(200);
        printf(&quot;UNAUTHORIZED&quot;);
        Lowerline();
        printf(&quot;ENTRY&quot;);
        printf(&quot;%c&quot;,26);
      }
    }
  }
}