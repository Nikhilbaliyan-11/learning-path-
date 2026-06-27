document.addEventListener('DOMContentLoaded', () => {
    const visitorCountElement = document.getElementById('visitorCount');
    const errorMessageElement = document.getElementById('errorMessage');

    
    const updateCounter = (count) => {
        visitorCountElement.textContent = count;
        visitorCountElement.classList.add('animate');
        setTimeout(() => {
            visitorCountElement.classList.remove('animate');
        }, 500);
    };

    
    const showError = (message) => {
        errorMessageElement.textContent = message;
        errorMessageElement.classList.remove('d-none');
        setTimeout(() => {
            errorMessageElement.classList.add('d-none');
        }, 5000);
    };

    
    const trackVisitor = async () => {
        try {
            console.log('Sending track visitor request...');
            const response = await fetch('/api/visitors/track', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                }
            });

            console.log('Response status:', response.status);
            
            if (!response.ok) {
                const errorData = await response.json();
                throw new Error(errorData.error || 'Failed to track visitor');
            }

            const data = await response.json();
            console.log('Track visitor response:', data);
            updateCounter(data.count);
        } catch (error) {
            console.error('Error in trackVisitor:', error);
            showError('Error tracking visitor: ' + error.message);
        }
    };

    const getCurrentCount = async () => {
        try {
            const response = await fetch('/api/visitors/count');
            if (!response.ok) {
                throw new Error('Failed to fetch visitor count');
            }
            const data = await response.json();
            updateCounter(data.count);
        } catch (error) {
            showError('Error fetching visitor count: ' + error.message);
        }
    };

    getCurrentCount();

    trackVisitor();

    setInterval(getCurrentCount, 30000);
}); 
