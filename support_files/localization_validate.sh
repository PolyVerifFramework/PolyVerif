#!/bin/bash

echo "Start AD Localization Validation "

gnome-terminal --tab --title="Localization Validation" --command="bash -c 'cd $HOME/PolyVerif; python3 localizationCalculation/LocalizationValidation.py; echo Report Generated; $SHELL'"



