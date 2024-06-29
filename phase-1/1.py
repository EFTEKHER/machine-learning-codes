import numpy as np
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, f1_score, recall_score, precision_score, confusion_matrix
from sklearn.svm import SVC
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import GradientBoostingClassifier, RandomForestClassifier

# Load the dataset
diabetes_dataset = pd.read_csv('diabetes.csv')

# Preprocess the data
X = diabetes_dataset.drop(columns='Outcome', axis=1)
Y = diabetes_dataset['Outcome']

# Data standardization
scaler = StandardScaler()
X_standardized = scaler.fit_transform(X)

# Split the data
X_train, X_test, Y_train, Y_test = train_test_split(X_standardized, Y, test_size=0.2, stratify=Y, random_state=2)

# Function to train and evaluate a model
def train_and_evaluate_model(model, X_train, Y_train, X_test, Y_test):
    model.fit(X_train, Y_train)
    Y_train_pred = model.predict(X_train)
    Y_test_pred = model.predict(X_test)
    
    metrics = {
        "accuracy_train": accuracy_score(Y_train, Y_train_pred),
        "recall_train": recall_score(Y_train, Y_train_pred),
        "precision_train": precision_score(Y_train, Y_train_pred),
        "f1_train": f1_score(Y_train, Y_train_pred),
        "confusion_matrix_train": confusion_matrix(Y_train, Y_train_pred),
        "accuracy_test": accuracy_score(Y_test, Y_test_pred),
        "recall_test": recall_score(Y_test, Y_test_pred),
        "precision_test": precision_score(Y_test, Y_test_pred),
        "f1_test": f1_score(Y_test, Y_test_pred),
        "confusion_matrix_test": confusion_matrix(Y_test, Y_test_pred),
    }
    return metrics

# Models
models = {
    "Support Vector Machine": SVC(kernel='linear'),
    "Logistic Regression": LogisticRegression(),
    "Decision Tree": DecisionTreeClassifier(),
    "Gradient Boosting": GradientBoostingClassifier(),
    "Random Forest": RandomForestClassifier()
}

# Train and evaluate each model
model_metrics = {}
for model_name, model in models.items():
    metrics = train_and_evaluate_model(model, X_train, Y_train, X_test, Y_test)
    model_metrics[model_name] = metrics

# Display the results
for model_name, metrics in model_metrics.items():
    print(f'\n{model_name}:')
    print(f'Train Accuracy: {metrics["accuracy_train"]:.4f}')
    print(f'Train Recall: {metrics["recall_train"]:.4f}')
    print(f'Train Precision: {metrics["precision_train"]:.4f}')
    print(f'Train F1 Score: {metrics["f1_train"]:.4f}')
    print(f'Train Confusion Matrix:\n{metrics["confusion_matrix_train"]}')
    print(f'Test Accuracy: {metrics["accuracy_test"]:.4f}')
    print(f'Test Recall: {metrics["recall_test"]:.4f}')
    print(f'Test Precision: {metrics["precision_test"]:.4f}')
    print(f'Test F1 Score: {metrics["f1_test"]:.4f}')
    print(f'Test Confusion Matrix:\n{metrics["confusion_matrix_test"]}')

# Function to make a prediction
def make_prediction(model, scaler, input_data):
    input_data_as_numpy_array = np.asarray(input_data)
    input_data_reshaped = input_data_as_numpy_array.reshape(1, -1)
    std_data = scaler.transform(input_data_reshaped)
    prediction = model.predict(std_data)
    return prediction[0]

# Get user input
def get_user_input():
    Pregnancies = int(input('Enter pregnancies: '))
    Glucose = int(input('Enter glucose level: '))
    BloodPressure = int(input('Enter blood pressure: '))
    SkinThickness = int(input('Enter skin thickness: '))
    Insulin = int(input('Enter insulin level: '))
    BMI = float(input('Enter BMI: '))
    DiabetesPedigreeFunction = float(input('Enter diabetes pedigree function: '))
    Age = int(input('Enter age: '))
    return (Pregnancies, Glucose, BloodPressure, SkinThickness, Insulin, BMI, DiabetesPedigreeFunction, Age)

# User selects model
def select_model(models):
    print("Select a model:")
    for i, model_name in enumerate(models.keys(), start=1):
        print(f"{i}. {model_name}")
    model_index = int(input("Enter the number of the model you want to use: ")) - 1
    selected_model_name = list(models.keys())[model_index]
    return models[selected_model_name], selected_model_name

# Example usage
input_data = get_user_input()
selected_model, selected_model_name = select_model(models)
print(f'You selected: {selected_model_name}')

prediction = make_prediction(selected_model, scaler, input_data)
if prediction == 0:
    print('The person is not diabetic')
else:
    print('The person is diabetic')
