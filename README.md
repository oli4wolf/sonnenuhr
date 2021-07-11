<h1> Eine etwas andere Sonnenuhr </h1>
<!-- wp:image {"align":"center","id":159,"width":378,"height":566,"sizeSlug":"large","linkDestination":"none"} -->
<div class="wp-block-image"><figure class="aligncenter size-large is-resized"><img src="http://www.owolf.ch/wp-content/uploads/2021/06/IMG_20210611_1734529-683x1024.jpg" alt="" class="wp-image-159" width="378" height="566"/></figure></div>
<!-- /wp:image -->

<!-- wp:paragraph -->
<p>Die Idee ist einfach: Bei einem Bild Hintergrundsbeleuchtung installieren und je nach Sonnenstand die entsprechende LED aufleuchten lassen. In den nautischen, astronomischen und civilen Leuchten das ganze Blau aufleuchten lassen.</p>
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
<p>Man nehme einen 5v Netzteil mit genügend Watt (je nach konsum der LEDs und ESP32) und einen Anschluss. (z.B.: https://www.adafruit.com/product/276 &amp; https://www.adafruit.com/product/368)<br>Ein LED Strip (hier im 90 Grad Winkel von Adafruit https://www.adafruit.com/product/3635).<br>Einen Kondensator für das Signal zwischen Microcontroller zum LED-Strip.<br>Ein ESP32 auf dem man diesen Code drauf spielen kann und voilà :-)</p>
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

<!-- wp:gallery {"ids":[158,159],"linkTo":"none"} -->
<figure class="wp-block-gallery columns-2 is-cropped"><ul class="blocks-gallery-grid"><li class="blocks-gallery-item"><figure><img src="http://www.owolf.ch/wp-content/uploads/2021/06/IMG_20210611_2015111-683x1024.jpg" alt="" data-id="158" data-full-url="http://www.owolf.ch/wp-content/uploads/2021/06/IMG_20210611_2015111-scaled.jpg" data-link="http://www.owolf.ch/2021/05/26/sunclock-mit-leds/img_20210611_2015111/" class="wp-image-158"/></figure></li><li class="blocks-gallery-item"><figure><img src="http://www.owolf.ch/wp-content/uploads/2021/06/IMG_20210611_1734529-683x1024.jpg" alt="" data-id="159" data-full-url="http://www.owolf.ch/wp-content/uploads/2021/06/IMG_20210611_1734529-scaled.jpg" data-link="http://www.owolf.ch/2021/05/26/sunclock-mit-leds/img_20210611_1734529/" class="wp-image-159"/></figure></li></ul></figure>
<!-- /wp:gallery -->
