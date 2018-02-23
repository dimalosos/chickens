typedef enum {
  BTN_EVENT_NONE = 0,
  BTN_EVENT_PRESSED,
  BTN_EVENT_RELEASED,  
} Btn_Event;

char message[] = "om mani padme hum\r\n";

Btn_Event get_btn_event(void) // generation btn state events
{
  static uint8_t btn_state_prev = 0;
  static uint8_t btn_state_debounced = 0;
  static uint16_t btn_debounce_cntr = 0;

  uint8_t btn_state = BTN_GPIO_READ_STATE(); // true corresponds to btn pressed
    
  // Debounce logic...
  if (btn_state_debounced != btn_state) {
    btn_state_debounced = btn_state;
    btn_debounce_cntr = DEBOUNCE_DELAY;     
  }
  if (btn_debounce_cntr > 0) {    
    btn_debounce_cntr--;
    return BTN_EVENT_NONE; 
  }
