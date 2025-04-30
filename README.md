# Fun Prank Website on ESP8266

This project turns an **ESP8266** into a **Wi-Fi access point** that serves a prank webpage simulating a virus installation process. The webpage displays a fake "hacked" message and a matrix-style animation to trick the user into thinking their device has been infected.

## Features:
- A fake virus installation progress bar.
- A "YOU HAVE BEEN HACKED" message that appears when the progress is complete.
- A matrix-like falling letters animation after the fake virus installation.

## Dependencies:
- **ESP8266** board (make sure you have the ESP8266 board package installed in your Arduino IDE).
- Libraries:
    - `ESP8266WiFi`
    - `WiFiClient`
    - `ESP8266WebServer`

## Setup Instructions:
1. Open the Arduino IDE.
2. Install the **ESP8266** board in the Arduino IDE if you haven't already.
3. Copy the code into the Arduino IDE.
4. Connect your ESP8266 to the computer and select the correct board and port from the **Tools** menu.
5. Upload the code to the ESP8266.
6. After uploading, the ESP8266 will start its own Wi-Fi network with the SSID: `Not_a_Virus` and password: `Quandingle7098`.
7. Connect to this Wi-Fi network with any device (e.g., laptop, smartphone).
8. Ideally, the site should open on the browser on its own, but if it doesn't open a browser and go to `http://192.168.4.1` to see the prank webpage in action!

## License:
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Troubleshooting:
- Ensure that your ESP8266 is correctly connected to your computer.
- Make sure you have selected the correct board (e.g., **LOLIN(WEMOS) R2 AND D1 mini**) from the **Tools** menu.
- If the webpage does not load, try restarting your ESP8266 or reconnecting to the Wi-Fi network.

## Future Enhancements:
- **Customizable Messages:** Allow users to customize the "hacked" message and progress bar text through a configuration file or web interface.
- **Sound Effects:** Add sound effects to the prank, such as alarming noises when the virus installation starts or when the "You have been hacked" message appears.
- **User Interaction:** Implement a fake security scan or fake diagnostic tool that asks the user for input (e.g., fake password input).
- **Multiple Pranks:** Include multiple pranks in one, like random pop-up windows or system notifications that seem to come from the computer's operating system.
- **Remote Control:** Allow the user to control the prank remotely through another webpage or app.
- **Mobile-Friendly:** Make the webpage responsive, so it looks good on both desktop and mobile devices.
- **Timer-Based Trigger:** Add a timer feature that will trigger the prank after a certain delay, such as a random time to make it more surprising.

## Contact
For any questions or contributions, feel free to contact me at keninish7965@gmail.com or connect via LinkedIn.
