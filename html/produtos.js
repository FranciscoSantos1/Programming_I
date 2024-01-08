const allFilterItems = document.querySelectorAll('filter-item');
const allFilterBtns = document.querySelectorAll('filter-btn');

allFilterBtns.forEach((btn) => {
    btn.addEventListener('click' , () => {
        showFilteredContent(btn);
    });
});

function showFilteredContent(btn){
    allFilterItems.forEach((item) => {
        if(item.classList.contains(btn.id)){
            item.style.display = "block";
        } else {
            item.style.display = "none";
        }
    });
}