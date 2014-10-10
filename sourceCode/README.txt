> Anleitung zum bauen unter Windows

- Öffne Cmake (min. Version ist 2.8)
- Oben bei "Where is the source code" auf "Browse Source" und den heruntergeladenen Ordner auswählen  (den Ordner in dem diese Datei liegt - Er muss die CmakeLists.txt Datei enthalten)
- Darunter bei "Where to build the binaries" den gleichen Pfad wählen und dahinter ein /BUILD setzen. Dadurch werden die gebauten Dateien in einen neuen Ordner erstellt.
- Danach unten auf "Configure" - Wenn es noch keinen BUILD Ordner in dem Verzeichnis gibt, fragt Cmake, ob er erstellt werden soll - mit "yes" bestätigen.
- Nun fragt Cmake nach dem generator. Hier ist es besonders wichtig, dass der richtige generator für deine IDE und den Compiler gewählt wird. Mit Finish bestätigen und Warten bis unten in der Konsole "Configuring done" erscheint.
- Danach über der Konsole auf "Generate klicken" und warten bis unten in der Konsole "Generating Done" erscheint (Tauchen dabei Warnings auf, können diese meist ignoriert werden)
- Im erstellten BUILD Ordner gibt es jetzt die entsprechenden Projektdateien.
- Diese können jetzt innerhalb der IDE gebuildet und verwendet werden. Der Ablauf ist bei jeder IDE leicht unterschiedlich (z.B. Visual Studio die .sln Datei im BUILD Verzeichnis öffnen und in Visual Studio oben auf BUILD -> build solution
	
- Die Resources (Texturen, Sounds) müssen extra heruntergeladen werden. - wird noch geklärt

- Wichtig: Da wir die einzelnen BUILD Ordner auf keinen Fall ins GIT einchecken sollten, habe ich im Hauptordner des Repositories
 eine .gitignore Datei erstellt. Die sorgt dafür, dass der Ordner ./sourceCode/BUILD nicht ins GIT geladen wird. Falls es weitere
 Ordner gibt, die nicht mit dem GIT synchronisiert werden sollen müssen die entsprechenden Pfade in der Datei ergänzt werden

===============================================================================================================================	
> Anleitung zum bauen unter Linux

//TODO

===============================================================================================================================	
===============================================================================================================================	
> Anleitung zum bauen unter MAC OSX

//TODO

===============================================================================================================================	



> Einfügen einer neuen Klasse in die Game-Engine

Neue Klassen müssen in den Ordner .\src\libraries\pge\ eingefügt werden.

> Anlegen einer neuen Executable (z.B. ein neues Example)

Um ein neues Executable anzulegen, muss in  .\src\executables ein neuer Ordner erstellt werden in den die entsprechenden .h und .cpp Dateien gehören. Zusätzlich muss eine CMakeLists.txt Datei vorhanden sein. Diese kann einfach aus einem der anderen Executable Ordnder z.B. Example01 kopiert werden.

> Hinzufügen von Resources (Texturen, Sounds...)

Resources gehören in das Verzeichnis .\resources\
	


