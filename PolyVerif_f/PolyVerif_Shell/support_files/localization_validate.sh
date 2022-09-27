#!/bin/bash

echo "Start AD Localization Validation "

gnome-terminal --tab --title="Localization Validation" --command="bash -c 'cd ../PolyVerif_Shell; python3 localizationCalculation/LocalizationValidation.py; echo Report Generated > ../PolyVerif_Shell/logfiles/logInfo.txt; exit; $SHELL'"




echo $$>>pidFile.txt