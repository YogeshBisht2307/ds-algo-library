



document.addEventListener("DOMContentLoaded", function(event){
    // code for admin pannel rich text editing 
  
    let sc = document.createElement('script')

    sc.setAttribute('src' , 'https://cdn.tiny.cloud/1/1aoq6ih3foosrenifzrt4e1e2hy40j9k2ag5apis89gnf2ux/tinymce/5/tinymce.min.js' );

    document.head.appendChild(sc);
    sc.onload = ()=>{
      
    tinymce.init({
        selector: '#id_code',
        width: 600,
        height: 300,
        plugins: [
            'print preview paste importcss searchreplace autolink autosave save directionality code visualblocks visualchars fullscreen image link media template codesample table charmap hr pagebreak nonbreaking anchor toc insertdatetime advlist lists wordcount imagetools textpattern noneditable help charmap quickbars emoticons',
        ],
        toolbar: 'undo redo | bold italic underline strikethrough | fontselect fontsizeselect formatselect | alignleft aligncenter alignright alignjustify | outdent indent |  numlist bullist | forecolor backcolor removeformat | pagebreak | charmap emoticons | fullscreen  preview save print | insertfile image media template link anchor codesample | ltr rtl',
        image_advtab: true,
        imagetools_cors_hosts: ['picsum.photos'],
        menu: {
        favs: {title: 'My Favorites', items: 'code visualaid | searchreplace | emoticons'}
        },
        menubar: 'favs file edit view insert format tools table help',
        content_css: 'css/content.css'
    });
    tinymce.init({
        selector: '#id_content',
        width: 600,
        height: 300,
        plugins: [
        'advlist autolink link image lists charmap print preview hr anchor pagebreak',
        'searchreplace wordcount visualblocks visualchars code fullscreen insertdatetime media nonbreaking',
        'table emoticons template paste help'
        ],
        toolbar: 'undo redo | styleselect | bold italic | alignleft aligncenter alignright alignjustify | ' +
        'bullist numlist outdent indent | link image | print preview media fullpage | ' +
        'forecolor backcolor emoticons | help',
        menu: {
        favs: {title: 'My Favorites', items: 'code visualaid | searchreplace | emoticons'}
        },
        menubar: 'favs file edit view insert format tools table help',
        content_css: 'css/content.css'
    });
    }
});