pipeline {
    agent any

    environment {
        EMAIL_RECIPIENTS = 'your-email@example.com'
    }

    stages {
        stage('Checkout Code') {
            steps {
                // Checkout code from GitHub
                git branch: 'main', url: 'https://github.com/your-repo/your-project.git'
            }
        }
        stage('Run Docker Containers') {
            steps {
                script {
                    // Ensure Docker and Docker Compose are installed and accessible
                    sh 'docker-compose --version'
                    sh 'docker --version'
                    
                    // Run Docker Compose
                    sh 'docker-compose up -d'
                }
            }
        }
    }

    post {
        always {
            // Notify via email
            mail to: EMAIL_RECIPIENTS,
                 subject: "Deployment Status: ${currentBuild.currentResult}",
                 body: """\
The deployment has been completed.

Build URL: ${env.BUILD_URL}
Build Result: ${currentBuild.currentResult}
"""
        }
    }
}
