// Selecione todos os botões "Adicionar"
const btnAdd = document.querySelectorAll('.btn-add');

// Crie uma matriz vazia para representar o carrinho de compras
let cart = [];

// Adicione um ouvinte de evento de clique a cada botão "Adicionar"
btnAdd.forEach(btn => {
  btn.addEventListener('click', () => {
    // Obtenha o identificador do produto do botão clicado
    const prodId = btn.dataset.prodId;

    // Encontre o elemento correspondente do produto na página
    const prodEl = document.querySelector(`[data-prod-id="${prodId}"]`);

    // Obtenha as informações do produto
    const prodName = prodEl.querySelector('.prod-name').textContent;
    const prodPrice = parseFloat(prodEl.querySelector('.prod-price').textContent);
    const prodQty = parseInt(prodEl.querySelector('.prod-qty').value);

    // Crie um objeto de produto com as informações do produto
    const product = {
      id: prodId,
      name: prodName,
      price: prodPrice,
      qty: prodQty
    };

    // Adicione o produto à matriz do carrinho de compras
    cart.push(product);

    // Atualize a exibição do carrinho de compras na página
    updateCart();
  });
});

// Função para atualizar a exibição do carrinho de compras na página
function updateCart() {
  // Selecione a tabela do carrinho de compras
  const cartTable = document.querySelector('#cart-table tbody');

  // Limpe a tabela do carrinho de compras
  cartTable.innerHTML = '';

  // Calcule o total do carrinho de compras
  let total = 0;

  // Adicione cada produto na tabela do carrinho de compras
  cart.forEach(prod => {
    // Calcule o preço total do produto
    const prodTotal = prod.price * prod.qty;

    // Crie uma nova linha na tabela do carrinho de compras com as informações do produto
    const tr = document.createElement('tr');
    tr.innerHTML = `
      <td>${prod.name}</td>
      <td>${prod.qty}</td>
      <td>R$ ${prod.price.toFixed(2)}</td>
      <td>R$ ${prodTotal.toFixed(2)}</td>
    `;
    cartTable.appendChild(tr);

    // Adicione o preço total do produto ao total do carrinho de compras
    total += prodTotal;
  });

  // Atualize a exibição do total do carrinho de compras na página
  const cartTotal = document.querySelector('#cart-total');
  cartTotal.textContent = `R$ ${total.toFixed(2)}`;
}