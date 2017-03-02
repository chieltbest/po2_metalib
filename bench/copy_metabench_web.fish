#!/usr/bin/fish

for collection in hetero type
    rm -r website/_$collection/$COMPILER
    rsync -am --include '*/' --include '*.html' --include '*.json' --exclude '*' build/benchmark/$collection/ website/_$collection/$COMPILER
    for chart in website/_$collection/$COMPILER/*/*.html
    	sed -i -e "1i---" -e "1itimestamp: "(date '+%a, %-d %b %Y') -e "1icompiler: $COMPILER" -e "1i---" $chart
    end
    for dataset in website/_$collecion/$COMPILER/*/*.json
    	sed -i -e "1i---" -e "1i---" $dataset
    end
end
