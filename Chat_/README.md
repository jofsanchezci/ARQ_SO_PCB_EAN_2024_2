
# Proyecto de Chat en Tiempo Real con Flask y Socket.IO

Este proyecto es un ejemplo básico de una aplicación de chat en tiempo real utilizando **Flask** y **Socket.IO** en Python.

## Estructura del Proyecto

La estructura de carpetas para este proyecto es la siguiente:

```
flask_chat_app/
│
├── app.py                 # Archivo principal que ejecuta el servidor Flask
├── requirements.txt        # Archivo con las dependencias necesarias (opcional)
├── templates/              # Carpeta para archivos HTML
│   └── chat.html           # Archivo HTML para la interfaz del chat
├── static/                 # Carpeta para archivos estáticos (CSS, JS)
```

### Descripción de Archivos

1. **`app.py`**: Contiene el código del servidor Flask y el manejo de WebSockets utilizando Flask-SocketIO. Este es el archivo principal de la aplicación.

2. **`requirements.txt`** (opcional): Contiene las dependencias necesarias para ejecutar la aplicación, como Flask y Flask-SocketIO. Se puede generar este archivo con los siguientes contenidos:
   ```
   Flask
   Flask-SocketIO
   ```

3. **`templates/`**: Contiene los archivos HTML que serán servidos por Flask. El archivo `chat.html` se utiliza para la interfaz del chat.

4. **`static/`** (opcional): Esta carpeta es útil para almacenar archivos estáticos como archivos CSS personalizados o archivos JavaScript descargados.

## Comandos para crear la estructura

Si deseas crear esta estructura manualmente, puedes seguir los siguientes comandos en la terminal:

```bash
mkdir flask_chat_app
cd flask_chat_app

# Crear el archivo principal
touch app.py

# Crear la carpeta templates y el archivo HTML
mkdir templates
touch templates/chat.html

# (Opcional) Crear el archivo requirements.txt
touch requirements.txt

# (Opcional) Crear carpeta para estáticos
mkdir static
```

### Instalación de Dependencias

Instala las dependencias necesarias ejecutando:

```bash
pip install Flask Flask-SocketIO
```

### Ejecución del Proyecto

1. Ejecuta la aplicación Flask con el siguiente comando:

   ```bash
   python app.py
   ```

2. Abre tu navegador web y visita `http://127.0.0.1:5000/` para acceder al chat en tiempo real.

### Atributos de Calidad

Este proyecto demuestra los siguientes atributos de calidad:

1. **Escalabilidad**: Flask-SocketIO permite manejar múltiples conexiones de cliente a través de WebSockets.
2. **Mantenibilidad**: La aplicación está estructurada con una separación clara entre el servidor Flask y los archivos HTML.
3. **Rendimiento**: La comunicación en tiempo real se realiza eficientemente con WebSockets, reduciendo la latencia de interacción entre cliente y servidor.

