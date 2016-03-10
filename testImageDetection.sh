#!/bin/bash

images=$(ls data/sampleCardImages/ | grep .jpg)
echo $images;
for img in $images
do
	./bin/main "data/sampleCardImages/$img";	
done
