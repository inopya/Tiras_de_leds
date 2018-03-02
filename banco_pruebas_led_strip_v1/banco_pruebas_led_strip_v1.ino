/*
#       _\|/_   A ver..., ¿que tenemos por aqui?
#       (O-O)        
# ---oOO-(_)-OOo---------------------------------
 
 
#################################################
# ********************************************* #
# *   BANCO DE PRUEBAS PARA UNA 'LEDStrip     * #
# *      Autor: Eulogio López Cayuela         * #
# *                                           * #
# *    Versión 1.0    Fecha: 03/12/2016       * #
# ********************************************* #
#################################################


// Parametro 1 = numero de pixels en la tira
// Parametro 2 = pin de Arduino al que esta conectada la tira (vale cualquiera)
// Parametro 3 = tipo de controlador de los led
//   NEO_KHZ800  800 KHz (w/WS2812)
//   NEO_KHZ400  400 KHz (WS2811)
//   NEO_GRB     Pixels en orden GRB (la gran mayoria)
//   NEO_RGB     Pixels en RGB
* 
// ejemplo de uso
// Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PIN, NEO_GRB + NEO_KHZ800 );

*/


//-----------------------------------------------------
#include <Adafruit_NeoPixel.h>                   	// Incluir biblioteca Adafruit NeoPixel
#define TIPO_LED            NEO_GRB + NEO_KHZ800 	//tipo controlador de los led
#define PIN_TIRA_LED        9       				// patilla para la tira
#define LONGITUD_TIRA      30   
//-----------------------------------------------------


// Crear el 'objeto' para controlar los led
Adafruit_NeoPixel tiraLEDS = Adafruit_NeoPixel(LONGITUD_TIRA , PIN_TIRA_LED, TIPO_LED);
//-----------------------------------------------------


//========================================================
//********************************************************
//         FUNCION DE CONFIGURACION
//********************************************************
//========================================================

void setup()
{
  Serial.begin(9600);  //Se inicia el puerto serie para depuracion

  pinMode(PIN_TIRA_LED, OUTPUT);  // pin para la linea DATA de los displays

  tiraLEDS.begin();  // Initializar el objeto 'tiraLEDS'

  //testLEDS(2500);  //descomentar esta linea para incluir untesteo completo en cada reinicio
  apagarTira();
  delay(500);

}


              
//========================================================
//********************************************************
//    BUCLE PRINCIPAL DEL PROGRAMA (Sistema vegetativo)
//********************************************************
//========================================================

void loop()
{ 
  tiraLEDS.setBrightness(255); //establecer la cantidad de brillo de TODOS los led (1-255)
  ejemplo(5000);
  apagarTira();
  delay(1000);
  testLEDS(2500);
 
}



//========================================================
//   FUNCION PARA ENCENDER LOS LED EN COLORES FIJOS
//========================================================

void ejemplo(int PAUSA)
{ 
  //direccionar  algunos led de forma independietne
  tiraLEDS.setBrightness(50);
  tiraLEDS.setPixelColor(0, tiraLEDS.Color(255,   0,   0)); //led 1 rojo
  tiraLEDS.setPixelColor(1, tiraLEDS.Color(  0, 255,   0)); //led 2 verde
  tiraLEDS.setPixelColor(2, tiraLEDS.Color(  0,   0, 255)); //led 3 azul
  tiraLEDS.setPixelColor(3, tiraLEDS.Color(255, 255, 255)); //led 4 blanco
  tiraLEDS.show();
  delay(PAUSA);
  tiraLEDS.setBrightness(255);  //cambair el brillo...
  tiraLEDS.show();				//mostar los mismos colores con el nuevo valor de brillo
  delay(PAUSA);

}



//========================================================
//  FUNCION PARA TESTEAR LA TIRA DE LED
//========================================================

void testLEDS(int PAUSA)
{
  //test ROJO de los leds
  for (int i=0; i<= LONGITUD_TIRA; i++){
    tiraLEDS.setPixelColor(i, tiraLEDS.Color(100, 0, 0));
  }
  tiraLEDS.show();
  delay(PAUSA);
  //test VERDE de los leds
  for (int i=0; i<= LONGITUD_TIRA; i++){
    tiraLEDS.setPixelColor(i, tiraLEDS.Color(0, 100, 0));
  }
  tiraLEDS.show();
  delay(PAUSA);
  //test AZUL de los leds
  for (int i=0; i<= LONGITUD_TIRA; i++){
    tiraLEDS.setPixelColor(i, tiraLEDS.Color(0, 0, 100));
  }
  tiraLEDS.show();
  delay(PAUSA);
  apagarTira();

}



//========================================================
//   FUNCION PARA APAGAR LA TIRA DE LED POR COMPLETO
//========================================================

void apagarTira()
{ 
  /* 
    esta funcion se encarga de apagar la tira de led recorriendo 
    todos los pixeles que la forman y los pone a Cero en sus tres componentes
  */

  for (int i=0; i<= LONGITUD_TIRA +1; i++){ 
    tiraLEDS.setPixelColor(i, tiraLEDS.Color(0, 0, 0));
  } 
  tiraLEDS.show(); 
}



//*******************************************************
//                    FIN DE PROGRAMA
//*******************************************************
