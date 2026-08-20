# Soldered Slider Potentiometer Qwiic Component

| ![Slider Potentiometer with Qwiic](https://cms.soldered.com/products/333131/media/333131_featured-photo_5bd23c.jpg) |
| :------------------------------------------------------------------------------------: |
|                    [Slider Potentiometer with Qwiic](https://www.solde.red/333131)             |

ESP-IDF driver for the Soldered Slider Potentiometer Qwiic board, part of the [Qwiic ecosystem](https://soldered.com/collections/qwiic-ecosystem). Reads the slider position over I2C via the board's onboard ATtiny (easyC firmware), as raw 10-bit ADC value (0-1023) or scaled percentage. The board's I2C address defaults to `0x30`, ORed with up to 3 bits set by the onboard DIP switches (`0x30`-`0x37`).

### Repository Contents

- **/src** - source files (.c)
- **/include** - header files (.h)
- **/examples** - examples for using the library
- **_other_** - idf_component.yml manifest file for ESP Component Registry

### Hardware design

You can find hardware design for this board in _Slider Potentiometer Qwiic_ hardware repository.

### Documentation

Access library documentation [here](https://docs.soldered.com/).

### About Soldered

<img src="https://raw.githubusercontent.com/SolderedElectronics/Soldered-Generic-Arduino-Library/dev/extras/Soldered-logo-color.png" alt="soldered-logo" width="500"/>

At Soldered, we design and manufacture a wide selection of electronic products to help you turn your ideas into acts and bring you one step closer to your final project. Our products are intented for makers and crafted in-house by our experienced team in Osijek, Croatia. We believe that sharing is a crucial element for improvement and innovation, and we work hard to stay connected with all our makers regardless of their skill or experience level. Therefore, all our products are open-source. Finally, we always have your back. If you face any problem concerning either your shopping experience or your electronics project, our team will help you deal with it, offering efficient customer service and cost-free technical support anytime. Some of those might be useful for you:

- [Web Store](https://www.soldered.com/shop)
- [Tutorials & Projects](https://soldered.com/learn)
- [Documentation](https://docs.soldered.com)

### Open-source license

Soldered invests vast amounts of time into hardware & software for these products, which are all open-source. Please support future development by buying one of our products.

Check license details in the LICENSE file. Long story short, use these open-source files for any purpose you want to, as long as you apply the same open-source licence to it and disclose the original source. No warranty - all designs in this repository are distributed in the hope that they will be useful, but without any warranty. They are provided "AS IS", therefore without warranty of any kind, either expressed or implied. The entire quality and performance of what you do with the contents of this repository are your responsibility. In no event, Soldered (TAVU) will be liable for your damages, losses, including any general, special, incidental or consequential damage arising out of the use or inability to use the contents of this repository.

## Have fun!

And thank you from your fellow makers at Soldered Electronics.
