# LEDChaser
Unser LEDChaser von der MakerFaire

`Chaser` wird automatisch generiert und kann nach dem Einbinden mittels `#include <LEDChaser.h>` genutzt werden.

Der verbaute Arduino Nano ist unter _Werkzeuge_ > _Boards_ auszuwählen. Für Bausätze, die ab 2016 erworben wurden, muss zusätzlich der Prozessor auf _ATmega168_ geändert werden.

## Funktionen

Alle Funktionen werden auf `Chaser` aufgerufen, also `Chaser.LEDan(2)` etwa.

`LEDan(led)` schaltet eine LED an – `led` kann 1-10 sein, alle anderen Werte schalten die LED auf dem Nano an.

`LEDaus(led)` schaltet eine LED aus – `led` kann 1-10 sein, alle anderen Werte schalten die LED auf dem Nano aus.

`LEDan(led, an/aus)` schaltet eine LED an oder aus – `led` kann 1-10 sein, alle anderen Werte schalten die LED auf
dem Nano an/aus. `an/aus` kann `AN` oder `AUS` sein.

`LEDpin(led)` liefert den Pin für eine LED von 1-10. Alternativ kann `LD1`-`LD10` genutzt werden.

`taster()` liefert `true` (`boolean`), wenn der Taster gedrückt ist.

`entprellen()` sollte aufgerufen werden, nachdem festgestellt wurde, dass der Taster gedrückt ist.

`poti()` liefert einen Wert von 0-1023 (`uint16_t`), je nach dem, wie weit das Potentiometer gedreht ist.
