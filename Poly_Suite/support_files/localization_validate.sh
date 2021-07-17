#!/bin/bash

echo "Start AD Localization Validation "

gnome-terminal --tab --title="Localization Validation" --command="bash -c 'cd ../Poly_Suite; python3 localizationCalculation/LocalizationValidation.py; echo Report Generated > ../Poly_Suite/logfiles/logInfo.txt;   $SHELL'"



