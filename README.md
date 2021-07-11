<h1> Eine etwas andere Sonnenuhr. </h1>
<!-- wp:image {"align":"center","id":159,"width":378,"height":566,"sizeSlug":"large","linkDestination":"none"} -->
<div class="wp-block-image"><figure class="aligncenter size-large is-resized"><img src="http://www.owolf.ch/wp-content/uploads/2021/06/IMG_20210611_1734529-683x1024.jpg" alt="" class="wp-image-159" width="378" height="566"/><figcaption>Finale</figcaption></figure></div>
<!-- /wp:image -->

<!-- wp:paragraph -->
<p>Die Idee ist einfach: Bei einem Bild Hintergrundsbeleuchtung installieren und je nach Sonnenstand die entsprechende LED aufleuchten lassen. In den nautischen, astronomischen und civilen Leuchten das ganze Blau aufleuchten lassen.<br>Dann weiss ich auch immer wann die Sonne am höchsten ist (und somit am stärksten).</p>
<!-- /wp:paragraph -->

<!-- wp:paragraph -->
<p>Erste Herausforderung war es an die Daten zu kommen. Selber Berechnen erwies sich als schwer denn der Sonnenstand ist abhängig zu Breitengrad und Datum.<br><br>Zuerst wollte ich selber das ganze berechnen aber nach längerer Lektüre auch per zufall noch eine suche nach einer API und tatsächlich was gefunden das perfekt mein Bedürfnis abdeckt. https://sunrise-sunset.org/api</p>
<!-- /wp:paragraph -->

<!-- wp:paragraph -->
<p>Der ESP32 ist nicht ganz ohne um ihn am Strom zu halten. Nach ein paar Stunden und versuchen ist die Lösung wie folgt:</p>
<!-- /wp:paragraph -->

<!-- wp:image {"id":155,"width":456,"height":684,"sizeSlug":"large","linkDestination":"none"} -->
<figure class="wp-block-image size-large is-resized"><img src="http://www.owolf.ch/wp-content/uploads/2021/06/IMG_20210528_1632288-683x1024.jpg" alt="" class="wp-image-155" width="456" height="684"/></figure>
<!-- /wp:image -->

<!-- wp:heading -->
<h2>Anleitung zum selber bauen</h2>
<!-- /wp:heading -->

<!-- wp:paragraph -->
<p>Man nehme einen 5v Netzteil mit genügend Watt (je nach konsum der LEDs und ESP32) und einen Anschluss. (z.B.: https://www.adafruit.com/product/276 &amp; https://www.adafruit.com/product/368)<br>Ein LED Strip (hier im 90 Grad Winkel von Adafruit https://www.adafruit.com/product/3635).<br>Einen Kondensator für das Signal zwischen Microcontroller zum LED-Strip.<br>Ein ESP32 auf dem man diesen Code drauf spielen kann und voilà :-)<br><a href="https://github.com/oli4wolf/sonnenuhr/blob/main/esp32_RESTClient.ino" target="_blank" rel="noreferrer noopener">https://github.com/oli4wolf/sonnenuhr/tree/main</a></p>
<!-- /wp:paragraph -->

<!-- wp:heading -->
<h2>Mögliche Verbesserungen</h2>
<!-- /wp:heading -->

<!-- wp:paragraph -->
<p>Normalerweise müsste die LED (Da rechtwinklig angeordnet) nicht einfach sich vorwärts bewegen sondern mit ARCTAN zurückberechnet werden, welchen Winkel der aktuelle Stand bedeutet und den nächsten LED aufleuchten lassen.<br>Dies könnte noch verbessert werden.</p>
<!-- /wp:paragraph -->

<!-- wp:paragraph -->
<p>Plus könnte der der Sonnenstand am Anfang oder ende des Tages verändern je nach Winkel der Sonne. Das könnte ich noch nachholen.</p>
<!-- /wp:paragraph -->

<!-- wp:paragraph -->
<p>Egal funktioniert:</p>
<!-- /wp:paragraph -->

<!-- wp:image {"width":398,"height":597} -->
<figure class="wp-block-image is-resized"><img src="https://lh3.googleusercontent.com/o2xv8E4PpijFsluOTld1kNY1Ux02Deb3ICKGsyKML_Ifjc_sqeV2nDk9e8ZOYeSjmzPmmd20K3AbJBQ591_9q8DnGn89CrKDaVvFqGS1EoCCsZD5pXI9PTqepoHraYwmTAd0J5Ry9IaoxcFI9Ti5wEhp4I5GETGUdJLP7ebFqiEntp8mwgN5aWY2hjkC2tw8r-9ZYSQ5S0nOWCLTIBK44reUH7zpFLjWv_Skh5YsRVHsBrVYr4OK5P5WEYcyhK3-uiXIzhgp_8-KIRp3moclbQYHav_IaskESsQu8JZLIvnhR9m0gTicbVIgNOGCwtS6x1mOhGRhkP2NAoLsUhbX6IDjgUXZa5icLtvrw3slDQeaM10HhViATjW-fvDjX21jivpMlDwU-HakRhuwthfPFuHsltO4Sdocltwqhwkgq6Rqx0G8so-PCMbqdt3R92adpVAjejpXuSHkfi9YU-7SIXBlBmJwalun0nEVSbIUNCGqfGtRU_Au063Pi9WaKoveIfHDydpq29N9lBSMEZ0z3mai10BvT-svdAxZf3d60t4jefuI3wWJdCJoWMt3ikdES28LL0Lt3rWzWjyXVTVAbXtfcpohY_Pjlvm57-nhk_-Bpjr3J5-DgWMtGyxNQW7lCo0zdGuC6yZO2nMiEfxfewE3axqMFpyLS3XXjBLi7HengpL2QG-TBK8d5HD8tuF4mcxJyJKt6q0in0mlOuTmcxA=w1325-h1986-no?authuser=0" alt="" width="398" height="597"/></figure>
<!-- /wp:image -->
