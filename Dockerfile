# Stage 1: Build the C program
FROM alpine:latest as builder

# Install build essentials
RUN apk add --no-cache build-base

# Copy the C source file
COPY logargs.c /src/logargs.c

# Compile the program
WORKDIR /src
RUN gcc -static -o logargs logargs.c

# Stage 2: Create the final image from scratch
FROM scratch

# Copy the compiled program
COPY --from=builder /src/logargs /logargs

# Set the compiled program as the entrypoint
ENTRYPOINT ["/logargs"]
