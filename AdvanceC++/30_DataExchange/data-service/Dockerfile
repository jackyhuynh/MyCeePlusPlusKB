# Use GCC as the base image
FROM gcc:latest

# Set working directory inside the container
WORKDIR /usr/src/app

# Copy the current directory contents into the container
COPY . .

# Compile the C++ program
RUN g++ -o data-service main.cpp

# Run the compiled program
CMD ["./data-service"]
