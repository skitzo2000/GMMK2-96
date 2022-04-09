enum custom_keycodes {
    PRNTSCREEN = SAFE_RANGE,
    NAME,
    GOOD_MORNING,
    HAPPY_MONDAY,
    HAPPY_FRIDAY,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PRNTSCREEN:
        if (record->event.pressed) {
            SEND_STRING(SS_RGUI(SS_RSFT("s")));
        } else {

        }
        break;
    case NAME:
        if (record->event.pressed) {
            SEND_STRING("Your Name Here");
        } else {

        }
        break;
    case GOOD_MORNING:
        if (record->event.pressed) {
            SEND_STRING("Good Morning, ");
        } else {

        }
        break;
    case HAPPY_MONDAY:
        if (record->event.pressed) {
            SEND_STRING("Happy Monday, ");
        } else {

        }
        break;
    case HAPPY_FRIDAY:
        if (record->event.pressed) {
            SEND_STRING("Happy Friday, ");
        } else {

        }
        break;
    }
    return true;
};