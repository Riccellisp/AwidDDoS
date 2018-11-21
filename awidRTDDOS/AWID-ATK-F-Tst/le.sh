#!/bin/bash
for filename in "11"; do
split -l 10000 $filename $filename 
done
