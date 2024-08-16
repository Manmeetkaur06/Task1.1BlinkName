v// Pin Definitions
const int ledPin = 13; // LED pin
const int buttonPin = 2; // Push button pin

// Morse Code Timing Definitions
const int dotTime = 200; // Duration of a dot
const int dashTime = dotTime * 4; // Duration of a dash
const int letterSpace = dotTime * 3; // Space between letters
const int wordSpace = dotTime * 7; // Space between words

// State Variables
bool buttonPressed = false;
bool reset = false;

// Morse Code Definitions
String morseCode = "-- .- -. -- . . -"; // Morse code for "Manmeet"

// Setup function
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, FALLING);
}

// Main loop function
void loop() {
  if (reset) {
    blinkName();
    reset = false;
  }
}

// Function to handle button press interrupt
void handleButtonPress() {
  reset = true;
}

// Function to blink the Morse code
void blinkName() {
  for (int i = 0; i < morseCode.length(); i++) {
    char symbol = morseCode.charAt(i);
    if (symbol == '.') {
      blinkDot();
    } else if (symbol == '-') {
      blinkDash();
    }
    delay(letterSpace); // Space between letters
  }
  delay(wordSpace); // Space between words
}

// Function to blink a dot
void blinkDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotTime);
  digitalWrite(ledPin, LOW);
  delay(dotTime); // Space between symbols
}

// Function to blink a dash
void blinkDash() {
  digitalWrite(ledPin, HIGH);
  delay(dashTime);
  digitalWrite(ledPin, LOW);
  delay(dotTime); // Space between symbols
}
