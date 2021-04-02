#pragma once

namespace EventSystem {

    using ButtonCode = uint16_t;

    namespace Button {

        // From glfw3 key codes
        enum : ButtonCode {
            Button0                = 0,
            Button1                = 1,
            Button2                = 2,
            Button3                = 3,
            Button4                = 4,
            Button5                = 5,
            Button6                = 6,
            Button7                = 7,

            ButtonLast             = Button7,
            ButtonLeft             = Button0,
            ButtonRight            = Button1,
            ButtonMiddle           = Button2
        };

    } // namespace Mouse

} // namespace EventSystem::Button

