# Data Exchange

## Structure
```css
./source/19_DataExchange/
    ├── data-service/
    │   ├── main.cpp
    │   └── Dockerfile
    ├── client-service/
    │   ├── main.cpp
    │   └── Dockerfile
    └── docker-compose.yml
```

## Run the App:

### Steps to Build and Run:
1. Navigate to the root of your project (where `docker-compose.yml` is located).

```bash
# in my case, my stater location is CPLUS_SAMPLE_CODE directory
cd source/19_DataExchange
```

2. Run the following command:

```bash
docker-compose up --build
```

### Stopping the Services:
To stop the services and remove the containers, run:

```bash
docker-compose down
```
## Result:

```css
 ✔ Container data-service-container    Recreated                                             0.0s 
 ✔ Container client-service-container  Recreated                                             0.0s 
Attaching to client-service-container, data-service-container
data-service-container    | Server listening on port: 8080
client-service-container  | Hello message sent from client-service
client-service-container  | Client received: Hello from Server
data-service-container    | Server received: Hello from Client
data-service-container    | Hello message sent from data-service
data-service-container exited with code 0
client-service-container exited with code 0
```
- Explain:
    - data-service acts as the server, listening on port 8080, and responds to messages from client-service.
    - client-service acts as the client, connects to data-service, sends a message, and receives a response.
    - Docker Compose handles networking and ensures that the services can communicate with each other using service names.
    - This setup allows developer to simulate microservices that communicate over a network using sockets.