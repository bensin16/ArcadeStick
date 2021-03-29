#include <XInput.h>
#include <AceButton.h>

using namespace ace_button;

// Constants //

// Reassign these to what pins you want to use for each XInput button //
const int BUTTON_A_PIN = 0;
const int BUTTON_X_PIN = 1;
const int BUTTON_RB_PIN = 2;
const int BUTTON_RT_PIN = 3;
const int BUTTON_START_PIN = 4;
const int BUTTON_LOGO_PIN = 5;
const int DPAD_LEFT_PIN = 6;
const int DPAD_DOWN_PIN = 8;

// row 2
const int BUTTON_B_PIN = 9;
const int BUTTON_Y_PIN = 10;
const int BUTTON_LB_PIN = 11;
const int BUTTON_LT_PIN = 12;
const int BUTTON_BACK_PIN = 13;
//analogs
const int DPAD_UP_PIN = A4;
const int DPAD_RIGHT_PIN = A5;

// Initalize ace buttons
AceButton button_b(BUTTON_B_PIN);
AceButton button_a(BUTTON_A_PIN);
AceButton button_x(BUTTON_X_PIN);
AceButton button_y(BUTTON_Y_PIN);
AceButton button_lb(BUTTON_LB_PIN);
AceButton button_lt(BUTTON_LT_PIN);
AceButton button_rb(BUTTON_RB_PIN);
AceButton button_rt(BUTTON_RT_PIN);
AceButton button_start(BUTTON_START_PIN);
AceButton button_back(BUTTON_BACK_PIN);
AceButton dpad_up(DPAD_UP_PIN);
AceButton dpad_down(DPAD_DOWN_PIN);
AceButton dpad_left(DPAD_LEFT_PIN);
AceButton dpad_right(DPAD_RIGHT_PIN);


// Forward reference handle event function
void handleEvent(AceButton*, uint8_t, uint8_t);

void setup() {
  // set up buttons with pullup
  pinMode(BUTTON_B_PIN, INPUT_PULLUP);
  pinMode(BUTTON_A_PIN, INPUT_PULLUP);
  pinMode(BUTTON_X_PIN, INPUT_PULLUP);
  pinMode(BUTTON_Y_PIN, INPUT_PULLUP);
  pinMode(BUTTON_LB_PIN, INPUT_PULLUP);
  pinMode(BUTTON_LT_PIN, INPUT_PULLUP);
  pinMode(BUTTON_RB_PIN, INPUT_PULLUP);
  pinMode(BUTTON_RT_PIN, INPUT_PULLUP);
  pinMode(BUTTON_START_PIN, INPUT_PULLUP);
  pinMode(BUTTON_BACK_PIN, INPUT_PULLUP);
  pinMode(DPAD_UP_PIN, INPUT_PULLUP);
  pinMode(DPAD_DOWN_PIN, INPUT_PULLUP);
  pinMode(DPAD_LEFT_PIN, INPUT_PULLUP);
  pinMode(DPAD_RIGHT_PIN, INPUT_PULLUP);


  // Configure ButtonConfig with event handler and enable higher level events
  ButtonConfig* buttonConfig = ButtonConfig::getSystemButtonConfig();
  buttonConfig->setEventHandler(handleEvent);
}

void loop() {
  // Check each button for changes in state each loop
  button_b.check();
  button_a.check();
  button_x.check(); 
  button_y.check();
  button_lb.check();
  button_lt.check();
  button_rb.check();
  button_rt.check();
  button_start.check();
  button_back.check();
  dpad_up.check();
  dpad_down.check();
  dpad_left.check();
  dpad_right.check();
}

void handleEvent(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  /** 
  Handle event function,
  press/release XInput button based on event type and pin
  */
  switch (eventType) {
    case AceButton::kEventPressed:

      // REPLACE THIS SWITCH WITH A MAP OR CUSTOM OBJECT
      switch (button->getPin()) {
        case BUTTON_B_PIN:
          XInput.press(BUTTON_B);
          break;
        case BUTTON_A_PIN:
          XInput.press(BUTTON_A);
          break;
        case BUTTON_X_PIN:
          XInput.press(BUTTON_X);
          break;
        case BUTTON_Y_PIN:
          XInput.press(BUTTON_Y);
          break;
        case BUTTON_LB_PIN:
          XInput.press(BUTTON_LB);
          break;
        case BUTTON_LT_PIN:
          XInput.press(TRIGGER_LEFT);
          break;
        case BUTTON_RB_PIN:
          XInput.press(BUTTON_RB);
          break;
        case BUTTON_RT_PIN:
          XInput.press(TRIGGER_RIGHT);
          break;
        case BUTTON_START_PIN:
          XInput.press(BUTTON_START);
          break;
        case BUTTON_BACK_PIN:
          XInput.press(BUTTON_BACK);
          break;
        case DPAD_LEFT_PIN:
          XInput.press(DPAD_LEFT);
          break;
        case DPAD_RIGHT_PIN:
          XInput.press(DPAD_RIGHT);
          break;
        case DPAD_UP_PIN:
          XInput.press(DPAD_UP);
          break;
        case DPAD_DOWN_PIN:
          XInput.press(DPAD_DOWN);
          break;
      }
      break;

    case AceButton::kEventReleased:
      switch (button->getPin()) {
        case BUTTON_B_PIN:
          XInput.release(BUTTON_B);
          break;
        case BUTTON_A_PIN:
          XInput.release(BUTTON_A);
          break;
        case BUTTON_X_PIN:
          XInput.release(BUTTON_X);
          break;
        case BUTTON_Y_PIN:
          XInput.release(BUTTON_Y);
          break;
        case BUTTON_LB_PIN:
          XInput.release(BUTTON_LB);
          break;
        case BUTTON_LT_PIN:
          XInput.release(TRIGGER_LEFT);
          break;
        case BUTTON_RB_PIN:
          XInput.release(BUTTON_RB);
          break;
        case BUTTON_RT_PIN:
          XInput.release(TRIGGER_RIGHT);
          break;
        case BUTTON_START_PIN:
          XInput.release(BUTTON_START);
          break;
        case BUTTON_BACK_PIN:
          XInput.release(BUTTON_BACK);
          break;
        case DPAD_LEFT_PIN:
          XInput.release(DPAD_LEFT);
          break;
        case DPAD_RIGHT_PIN:
          XInput.release(DPAD_RIGHT);
          break;
        case DPAD_UP_PIN:
          XInput.release(DPAD_UP);
          break;
        case DPAD_DOWN_PIN:
          XInput.release(DPAD_DOWN);
          break;
      }
      break;
  }
}
