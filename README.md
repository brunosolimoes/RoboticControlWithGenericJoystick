Usei como base o arquivo de exemplo que vem na biblioteca USBHost shield library 2.0 -> HID -> HID -> USBHIDjoystick.
Baixei via IDE do arduino.

Usei um controle Génerico como o mostrado na foto. Um Direcional Pad a esqueda, 4 botões a direita, start e
select e 4 botões na parte de trás do controle.
(https://www.reddit.com/media?url=https%3A%2F%2Fpreview.redd.it%2Fdicas-para-controle-de-pc-v0-bt9224vevtea1.jpg%3Fwidth%3D640%26crop%3Dsmart%26auto%3Dwebp%26s%3D0dc2e2cedab517fdcc474ccae716046f6b07c48b)

Os motores estão numerados da base para a garra.

Os eixos X e Y do Dpad controla os 2 primeiros motoes, os 4 botões os 2 motores seguinte no mesmo esquema(os
na vertical controlam um motor e os na horizontal controlam o seguinte), os gatilhos de cima controlam o
penultimo motor e os de baixo controlam a garra.

os botões star e select não são usados, mas eles são lidos pelo código.
