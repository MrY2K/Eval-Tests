#!/bin/bash

# Create Dockerfile
cat <<EOF > Dockerfile
FROM alpine:latest
RUN apk add --no-cache gcc make cmake valgrind vim clang g++
EOF

# Wait for 2 seconds
sleep 2

# Build the Docker image
docker build -t test .

# Wait for 2 seconds
sleep 2

# Run the Docker container with volume mount
docker run -it -v "$PWD":/home test

# Wait for 2 seconds
sleep 2