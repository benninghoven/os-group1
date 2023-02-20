#!/bin/bash

IMAGE="groupassignment1_image"
CONTAINER="groupassignment1_coontainer"

found=$(docker images -q $IMAGE)

# if image is not found
if [ -z "$found" ]; then
  echo "🐳 Image not found, creating..."
  docker build -t $IMAGE .
else
  echo "🐳 Image found"
fi

docker run -it \
    -v $(pwd)/main.cc:/app/main.cc \
    --name $CONTAINER \
    $IMAGE

# auto delete container after it ran
docker rm $CONTAINER
make clean
