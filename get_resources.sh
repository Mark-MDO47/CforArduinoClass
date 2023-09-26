cd /d/github-Mark-MDO47/CforArduinoClass
grep "Mark-MDO47/ArduinoClass.*Images" `findn "*.md"` | sed "s?^.*/master/??" | sed "s?\"* .*??" | sort | uniq > images.mdo
grep "Mark-MDO47/ArduinoClass.*[.]pdf" `findn "*.md"` | sed "s?^.*/master/??" | sed "s?\"* .*??" | sort | uniq > pdfs.mdo


