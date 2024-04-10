# Container Argument Logger

This project provides a super-lightweight container image that logs any arguments passed to it at startup, then sleeps indefinitely, awaiting a signal for a graceful shutdown. It demonstrates efficient container image creation using multi-stage builds and basic UNIX signal handling in a C program.

## Features

- Ultra-lightweight container image, ideal for minimalistic deployments
- Logs startup arguments
- Graceful shutdown support on receiving `SIGINT` and `SIGTERM`

## Prerequisites

- Docker or any OCI compatible container runtime for local testing and image building
- Access to a Kubernetes cluster and `kubectl` configured for Kubernetes examples

## Using the Container Image

You can either build the container image yourself or use the pre-built multi-architecture version available on Docker Hub `spurin/container-args`

### Building the Container Image

To build the image yourself, clone this repository or download the source code, then navigate to the directory containing the Dockerfile. Use the following command:

```sh
docker build -t spurin/container-args .
```

## Using the Pre-Built Image

Alternatively, you can use the pre-built image available on Docker Hub without needing to build it yourself:

```sh
docker pull spurin/container-args
```

# Running the Container Image

## Docker

```sh
docker run -it --rm spurin/container-args arg1 arg2 arg3
```

## Kubernetes

```sh
kubectl apply -f - <<EOF
apiVersion: v1
kind: Pod
metadata:
  name: container-args
spec:
  containers:
  - name: container-args
    image: spurin/container-args
    args: ["arg1", "arg2", "arg3"]
EOF
```

You can then view the logs accordingly -

```sh
kubectl logs pod/container-args
```

# Signal Handling

The application runs indefinitely until receiving a SIGINT or SIGTERM, after which it logs the received signal and exits gracefully.

# Development

Modify the C source code (logargs.c) as needed for further customisation. Remember to rebuild the container image to apply your changes.
