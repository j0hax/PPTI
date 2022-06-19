# Teilaufgabe 1 (d)

>Warum ist es – abgesehen von einem höheren Grad an Realismus – sinnvoll, den
`std::vector` vollständig zu durchmischen und Karten vom Ende zu entnehmen,
anstatt das Mischen zu sparen und Karten an zufälligen Indizes zu entnehmen?
Schreiben Sie Ihre Begründung bitte in eine separate Datei.

Es ist effizienter, ein mal zu mischen und dann Karten aus dem Ende eines `std::vector`s zu entnehmen. Würde man an zufälligen Indizes Elemente entfernen, müssen jedes mal alle weiteren Elemente verschoben werden.