#!/bin/bash
for filename in *; do
split -l 10000 $filename $filename 
done
